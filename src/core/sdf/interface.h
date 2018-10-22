#pragma once

#include "core/grid.h"

class Sdf
{
public:

    Sdf();
    virtual ~Sdf() = default;

    virtual void apply(Grid *grid) const = 0;
};
