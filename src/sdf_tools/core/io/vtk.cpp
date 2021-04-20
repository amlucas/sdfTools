#include "vtk.h"

#include <sdf_tools/core/utils/file.h>

#include <fstream>
#include <type_traits>
#include <vector>

namespace sdf_tools {
namespace io {

static const std::string ext = ".vtk";

static std::vector<float> getFloatData(const Grid *grid)
{
    const auto& data = grid->getData();
    std::vector<float> d;
    d.reserve(data.size());

    for (auto val : data)
        d.push_back(val);

    return d;
}

void writeVtk(std::string basename, const Grid *grid)
{
    const std::string fname = basename + ext;
    std::ofstream stream(fname);

    const auto n     = grid->getDimensions();
    const auto start = grid->getOffsets();
    const auto h     = grid->getSpacing();
    const auto data  = getFloatData(grid);

    stream << "# vtk DataFile Version 2.0\n"
           << "SDF field\n"
           << "ASCII\n";

    stream << "DATASET STRUCTURED_POINTS\n"
           << "DIMENSIONS " << n.x << ' ' << n.y << ' ' << n.z << '\n'
           << "ORIGIN " << start.x << ' ' << start.y << ' ' << start.z << '\n'
           << "SPACING " << h.x << ' ' << h.y << ' ' << h.z << '\n';

    stream << "POINT_DATA " << data.size() << "\n"
           << "SCALARS sdf float\n"
           << "LOOKUP_TABLE default\n";

    for (auto val : data)
        stream << val << '\n';
}

} // namespace io
} // namespace sdf_tools
