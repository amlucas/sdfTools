#pragma once

#include <vector>
#include "types.h"

class Grid
{
public:
    Grid(int3 dimensions, real3 offsets, real3 extents);
    Grid(PyInt3 dimensions, PyReal3 offsets, PyReal3 extents);

    const real* data() const { return field.data(); }
    real*       data()       { return field.data(); }

    int3 getDimensions() const;
    real3 getExtents() const;
    real3 getOffsets() const;
    std::vector<real> getData() const;

private:
    std::vector<real> field;

    int3 dimensions;
    real3 offsets;
    real3 extents;
};
