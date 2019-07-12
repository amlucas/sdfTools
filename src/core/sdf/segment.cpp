#include "segment.h"
#include "common.h"

#include <core/utils/error.h>
#include <core/utils/helper_math.h>
#include <core/grid.h>


SdfSegment::SdfSegment(real3 start, real3 end, real radius, bool inside) :
    start(start),
    seg(end - start),
    radius(radius),
    sign(inside ? 1 : -1)
{
    constexpr real eps = 1e-6;
    real segSq = dot(seg, seg);
    
    if (segSq < eps)
        error("SdfSegment: Start and End points must be different");

    invSegSq = 1.0_r / segSq;
}

SdfSegment::SdfSegment(PyReal3 start, PyReal3 end, real radius, bool inside) :
    SdfSegment(make_real3(start),
               make_real3(end),
               radius, inside)
{}

real SdfSegment::at(real3 r) const
{
    auto ar = r - start;
    real alpha = dot(seg, ar) * invSegSq;
    alpha = std::min(1.0_r, std::max(0.0_r, alpha));
    auto p = start + alpha * seg;

    return sign * (length(r - p) - radius);
}

#define CLASS_NAME SdfSegment
GENERATE_IMPL_OPERATIONS()
