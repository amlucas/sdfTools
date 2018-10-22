#pragma once

#include "grid.h"

class Sdf
{
public:

    Sdf(int3 dimensions, real3 extents);

protected:

    Grid grid;
};
