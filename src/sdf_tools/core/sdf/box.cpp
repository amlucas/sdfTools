#include "box.h"

#include <sdf_tools/core/utils/helper_math.h>

#include <algorithm>

namespace sdf_tools {
namespace sdf {

SdfBox::SdfBox(real3 lowerBound, real3 upperBound, bool inside) :
    center_(0.5_r * (lowerBound+upperBound)),
    halfExtents_(0.5_r * (upperBound-lowerBound)),
    sign_(inside ? 1 : -1)
{}

real SdfBox::at(real3 r) const
{
    r -= center_;
    real3 d {std::max(r.x - halfExtents_.x, -r.x - halfExtents_.x),
             std::max(r.y - halfExtents_.y, -r.y - halfExtents_.y),
             std::max(r.z - halfExtents_.z, -r.z - halfExtents_.z)};

    return sign_ * std::max(d.x, std::max(d.y, d.z));
}

} // namespace sdf
} // namespace sdf_tools
