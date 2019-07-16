#include "box.h"
#include "common.h"

#include <core/utils/helper_math.h>
#include <core/grid.h>


SdfBox::SdfBox(real3 lowerBound, real3 upperBound, bool inside) :
    center(0.5_r * (lowerBound+upperBound)),
    halfExtents(0.5_r * (upperBound-lowerBound)),
    sign(inside ? 1 : -1)
{}

SdfBox::SdfBox(PyReal3 lowerBound, PyReal3 upperBound, bool inside) :
    SdfBox(make_real3(lowerBound),
           make_real3(upperBound),
           inside)
{}

real SdfBox::at(real3 r) const
{
    r -= center;
    real3 d {std::max(r.x - halfExtents.x, -r.x - halfExtents.x),
             std::max(r.y - halfExtents.y, -r.y - halfExtents.y),
             std::max(r.z - halfExtents.z, -r.z - halfExtents.z)};
             
    return sign * std::max(d.x, std::max(d.y, d.z));
}

#define CLASS_NAME SdfBox
GENERATE_IMPL_OPERATIONS()