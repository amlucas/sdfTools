#include "sphere.h"
#include "core/utils/helper_math.h"

#include "common.h"

SdfSphere::SdfSphere(real3 center, real radius, bool inside) :
    center(center), radius(radius),
    sign(inside ? 1 : -1)
{}

SdfSphere::SdfSphere(PyReal3 center, real radius, bool inside) :
    SdfSphere(make_real3(center), radius, inside)
{}

void SdfSphere::apply(Grid *grid) const
{
    common::apply(this, grid);
}

real SdfSphere::at(real3 r) const
{
    return sign * (length(r - center) - radius);
}
