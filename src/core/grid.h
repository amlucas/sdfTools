#pragma once

#include "types.h"

#include <array>
#include <string>
#include <vector>

class Grid
{
public:
    Grid(int3 dimensions, real3 offsets, real3 extents);
    Grid(PyInt3 dimensions, PyReal3 offsets, PyReal3 extents);

    Grid(const Grid& other);
    Grid(Grid&& other);
    Grid& operator=(Grid other);
    
    ~Grid();
    
    friend void swap(Grid& a, Grid& b);

    const real* data() const { return field.data(); }
    real*       data()       { return field.data(); }

    int3 getDimensions() const;
    real3 getExtents() const;
    real3 getOffsets() const;
    real3 getSpacing() const;
    
    std::vector<real>&       getData();
    const std::vector<real>& getData() const;

    void dumpBov(std::string basename) const;
    void dumpSdf(std::string basename) const;

    void applySdfComplement();
    void applySdfInteriorUnion(const Grid *other);
    void applySdfInteriorIntersection(const Grid *other);
    void applySdfSubtract(const Grid *other);

    using FlipMap = std::array<char,3>;
    void flip(const FlipMap& map);
    
private:
    std::vector<real> field;

    int3 dimensions;
    real3 offsets;
    real3 extents;
};
