#include "sphere.h"

#include <sdf_tools/core/utils/helper_math.h>
#include <sdf_tools/core/grid.h>

namespace sdf_tools {
namespace sdf {

SdfSphere::SdfSphere(real3 center, real radius, bool inside) :
    center(center),
    radius(radius),
    sign(inside ? 1 : -1)
{}

real SdfSphere::at(real3 r) const
{
    return sign * (length(r - center) - radius);
}

} // namespace sdf
} // namespace sdf_tools
