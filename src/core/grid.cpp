#include "grid.h"
#include "io/write_bov.h"

Grid::Grid(int3 dimensions, real3 offsets, real3 extents) :
    dimensions(dimensions), offsets(offsets), extents(extents)
{
    field.resize(dimensions.x * dimensions.y * dimensions.z, 0);
}

Grid::Grid(PyInt3 dimensions, PyReal3 offsets, PyReal3 extents) :
    Grid(make_int3(dimensions), make_real3(offsets), make_real3(extents))
{}

int3 Grid::getDimensions() const { return dimensions; }

real3 Grid::getExtents() const { return extents; }
real3 Grid::getOffsets() const { return offsets; }

std::vector<real>& Grid::getData()
{
    return field;
}

void Grid::dumpBov(std::string basename) const
{
    writeBov(basename, this);
}
