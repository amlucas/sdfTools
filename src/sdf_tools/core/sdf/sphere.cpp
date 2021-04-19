#include "sphere.h"

#include <sdf_tools/core/utils/helper_math.h>

namespace sdf_tools {
namespace sdf {

SdfSphere::SdfSphere(real3 center, real radius, bool inside) :
    center_(center),
    radius_(radius),
    sign_(inside ? 1 : -1)
{}

real SdfSphere::at(real3 r) const
{
    return sign_ * (length(r - center_) - radius_);
}

} // namespace sdf
} // namespace sdf_tools
