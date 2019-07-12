#include "grid.h"

#include <core/io/write_bov.h>
#include <core/io/write_sdf.h>

Grid::Grid(int3 dimensions, real3 offsets, real3 extents) :
    dimensions(dimensions),
    offsets(offsets),
    extents(extents)
{
    field.resize(dimensions.x * dimensions.y * dimensions.z, 0);
}

Grid::Grid(PyInt3 dimensions, PyReal3 offsets, PyReal3 extents) :
    Grid(make_int3(dimensions),
         make_real3(offsets),
         make_real3(extents))
{}

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

void Grid::dumpBov(std::string basename) const
{
    writeBov(basename, this);
}

void Grid::dumpSdf(std::string basename) const
{
    writeSdf(basename, this);
}


template <typename Op>
inline void applyUnaryOperation(Grid *grid, Op op)
{
    for (auto& val : grid->getData())
        val = op(val);
}

template <typename Op>
inline void applyBinaryOperation(Grid *grid1, const Grid *grid2, Op op)
{
    auto dims = grid1->getDimensions();
    real *data1 = grid1->data();
    const real *data2 = grid2->data();

    for (int iz = 0; iz < dims.z; ++iz)
        for (int iy = 0; iy < dims.y; ++iy)
            for (int ix = 0; ix < dims.x; ++ix) {
                *data1 = op(*data1, *data2);
                ++data1;
                ++data2;
            }
}

void Grid::applySdfComplement()
{
    applyUnaryOperation(this, [](real a){return -a;});
}

void Grid::applySdfInteriorUnion(const Grid *other)
{
    applyBinaryOperation(this, other, [](real a, real b){return std::max(a, b);});
}

void Grid::applySdfInteriorIntersection(const Grid *other)
{
    applyBinaryOperation(this, other, [](real a, real b){return std::min(a, b);});
}

void Grid::applySdfSubtract(const Grid *other)
{
    applyBinaryOperation(this, other, [](real a, real b){return std::max(a, -b);});
}

