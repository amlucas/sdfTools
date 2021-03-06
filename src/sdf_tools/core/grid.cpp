#include "grid.h"

#include <sdf_tools/core/utils/error.h>

#include <array>

namespace sdf_tools {

Grid::Grid(int3 dimensions, real3 offsets, real3 extents) :
    dimensions(dimensions),
    offsets(offsets),
    extents(extents)
{
    field.resize(dimensions.x * dimensions.y * dimensions.z, 0);
}

Grid::Grid(const Grid& other) :
    field(other.field),
    dimensions(other.dimensions),
    offsets(other.offsets),
    extents(other.extents)
{}

Grid::Grid(Grid&& other)
{
    swap(*this, other);
}

Grid& Grid::operator=(Grid other)
{
    swap(*this, other);
    return *this;
}

Grid::~Grid() = default;

void swap(Grid& a, Grid& b)
{
    std::swap(a.field,      b.field);
    std::swap(a.dimensions, b.dimensions);
    std::swap(a.offsets,    b.offsets);
    std::swap(a.extents,    b.extents);
}

int3 Grid::getDimensions() const { return dimensions; }

real3 Grid::getExtents() const { return extents; }
real3 Grid::getOffsets() const { return offsets; }

real3 Grid::getSpacing() const
{
    return {extents.x / dimensions.x,
            extents.y / dimensions.y,
            extents.z / dimensions.z};
}

std::vector<real>& Grid::getData()
{
    return field;
}

const std::vector<real>& Grid::getData() const
{
    return field;
}

static const Grid::FlipMap identityFlipMap = "xyz";
using IntFlipMap = std::array<int, 3>;

inline void checkMap(const Grid::FlipMap& map)
{
    std::array<bool,3> valid {false, false, false};

    sdfToolsExpect(map.size() == 3, "invalid map '%s': must be of size 3", map.c_str());

    for (auto c : map)
    {
        if      (c == 'x') valid[0] = true;
        else if (c == 'y') valid[1] = true;
        else if (c == 'z') valid[2] = true;
        else
            sdfToolsDie("invalid map '%s': wrong character '%c' (must be 'x', 'y' or 'z')",
                        map.c_str(), c);
    }

    for (size_t i = 0; i < map.size(); ++i)
        sdfToolsEnsure(valid[i], "invalid map '%s': missing '%c'", map.c_str(), identityFlipMap[i]);
}

inline IntFlipMap convertMap(const Grid::FlipMap& map)
{
    auto getComp = [&](char c)
    {
        if      (c == 'x') return 0;
        else if (c == 'y') return 1;
        else               return 2;
    };

    return {getComp(map[0]),
            getComp(map[1]),
            getComp(map[2])};
}

template<typename T>
inline T flip3(const T& v0, const IntFlipMap& map)
{

    auto getComp = [&](char c)
    {
        if      (c == 0) return v0.x;
        else if (c == 1) return v0.y;
        else             return v0.z;
    };

    return {getComp(map[0]),
            getComp(map[1]),
            getComp(map[2])};
}

void Grid::flip(const Grid::FlipMap& map)
{
    checkMap(map);
    auto imap = convertMap(map);
    const Grid original(*this);

    dimensions = flip3(original.getDimensions(), imap);
    offsets    = flip3(original.getOffsets(),    imap);
    extents    = flip3(original.getExtents(),    imap);

    auto origDim = original.getDimensions();
    auto srcData = original.data();

    for (int iz = 0; iz < origDim.z; ++iz)
        for (int iy = 0; iy < origDim.y; ++iy)
            for (int ix = 0; ix < origDim.x; ++ix) {
                int3 dst = flip3(int3{ix, iy, iz}, imap);
                int dstId = dst.x + dimensions.x * (dst.y + dimensions.y * dst.z);
                field[dstId] = *srcData;
                ++srcData;
            }
}

void Grid::extrude(real zoffset, real zextent, int nz)
{
    sdfToolsExpect(dimensions.z == 1,
                   "can only extrude sdf from 'xy' plane (number of gridpoints along z must be 1)");

    extents.z = zextent;
    offsets.z = zoffset;
    dimensions.z = nz;

    const auto xySdf = field;

    field.resize(xySdf.size() * nz);

    for (int iz = 0; iz < nz; ++iz)
        std::copy(xySdf.begin(), xySdf.end(),
                  field.begin() + xySdf.size() * iz);
}

} // namespace sdf_tools
