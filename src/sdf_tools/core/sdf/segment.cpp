#include "segment.h"

#include <sdf_tools/core/utils/error.h>
#include <sdf_tools/core/utils/helper_math.h>
#include <sdf_tools/core/grid.h>

namespace sdf_tools {
namespace sdf {

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

real SdfSegment::at(real3 r) const
{
    auto ar = r - start;
    real alpha = dot(seg, ar) * invSegSq;
    alpha = std::min(1.0_r, std::max(0.0_r, alpha));
    auto p = start + alpha * seg;

    return sign * (length(r - p) - radius);
}

} // namespace sdf
} // namespace sdf_tools
