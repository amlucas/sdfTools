#pragma once

#include "types.h"

#include <vector>
#include <string>

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
    real3 getSpacing() const;
    
    std::vector<real>& getData();
    const std::vector<real>& getData() const;

    void dumpBov(std::string basename) const;
    void dumpSdf(std::string basename) const;

private:
    std::vector<real> field;

    int3 dimensions;
    real3 offsets;
    real3 extents;
};
