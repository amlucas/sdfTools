#include "sdf.h"

Sdf::Sdf(int3 dimensions, real3 extents) :
    grid(dimensions, extents)
{}
