#include "plate.h"

#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/utils/helper_math.h>

namespace sdf_tools {
namespace sdf {

SdfPlate::SdfPlate(real3 point, real3 normal) :
    point_(point),
    normal_(normal)
{
    const real nrm = length(normal_);
    normal_ *= real(1.0) / nrm;
}

real SdfPlate::at(real3 r) const
{
    const real3 dr = r - point_;
    return dot(dr, normal_);
}

} // namespace sdf
} // namespace sdf_tools
