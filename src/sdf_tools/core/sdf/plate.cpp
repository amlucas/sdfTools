#include "plate.h"

#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/utils/helper_math.h>

namespace sdf_tools {
namespace sdf {

SdfPlate::SdfPlate(real3 point, real3 normal) :
    point(point), normal(normal)
{
    real nrm = length(normal);
    normal *= (real(1.0) / nrm);
}

real SdfPlate::at(real3 r) const
{
    real3 dr = r - point;
    return -dot(dr, normal);
}

} // namespace sdf
} // namespace sdf_tools
