#include "grid.h"

Grid::Grid(int3 dimensions, real3 extents) :
    dimensions(dimensions), extents(extents)
{
    field.resize(dimensions.x * dimensions.y * dimensions.z, 0);
}

int3 Grid::getDimensions() const
{
    return dimensions;
}

real3 Grid::getExtents() const
{
    return extents;
}

