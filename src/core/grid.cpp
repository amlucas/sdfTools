#include "grid.h"

Grid::Grid(int3 dimensions, real3 offsets, real3 extents) :
    dimensions(dimensions), offsets(offsets), extents(extents)
{
    field.resize(dimensions.x * dimensions.y * dimensions.z, 0);
}

int3 Grid::getDimensions() const { return dimensions; }

real3 Grid::getExtents() const { return extents; }
real3 Grid::getOffsets() const { return offsets; }

std::vector<real> Grid::getData() const
{
    return field;
}
