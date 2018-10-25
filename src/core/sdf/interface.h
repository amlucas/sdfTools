#pragma once

#include "core/grid.h"

class Sdf
{
public:

    Sdf();
    virtual ~Sdf() = default;

    virtual void apply           (Grid *grid) const = 0;
    virtual void applyComplement (Grid *grid) const = 0;

    virtual void interiorUnion        (Grid *grid) const = 0;
    virtual void interiorIntersection (Grid *grid) const = 0;

    virtual void interiorSubtractToGrid (Grid *grid) const = 0;
    virtual void interiorSubtractGrid   (Grid *grid) const = 0;
};
