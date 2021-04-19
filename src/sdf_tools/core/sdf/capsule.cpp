#include "capsule.h"

#include <sdf_tools/core/utils/error.h>
#include <sdf_tools/core/utils/helper_math.h>

#include <algorithm>

namespace sdf_tools {
namespace sdf {

SdfCapsule::SdfCapsule(real3 start, real3 end, real radius, bool inside) :
    start_(start),
    seg_(end - start),
    radius_(radius),
    sign_(inside ? 1 : -1)
{
    constexpr real eps = 1e-6;
    const real segSq = dot(seg_, seg_);

    if (segSq < eps)
        error("SdfSegment: Start and End points must be different");

    invSegSq_ = 1.0_r / segSq;
}

real SdfCapsule::at(real3 r) const
{
    const real3 ar = r - start_;
    real alpha = dot(seg_, ar) * invSegSq_;
    alpha = std::min(1.0_r, std::max(0.0_r, alpha));
    const real3 p = start_ + alpha * seg_;

    return sign_ * (length(r - p) - radius_);
}

} // namespace sdf
} // namespace sdf_tools
