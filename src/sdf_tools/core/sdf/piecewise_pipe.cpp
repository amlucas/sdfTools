#include "piecewise_pipe.h"

#include <sdf_tools/core/utils/helper_math.h>

#include <algorithm>
#include <limits>
#include <vector>

namespace sdf_tools {
namespace sdf {

SdfPiecewisePipe::SdfPiecewisePipe(std::vector<real3> vertices, real radius, bool inside) :
    vertices_(std::move(vertices)),
    radius_(radius),
    insideSign_(inside ? 1 : -1)
{}

real SdfPiecewisePipe::at(real3 r) const
{
    const int n = (int) vertices_.size();

    real sdfTot = std::numeric_limits<real>::max();

    for (int i = 0; i < n-1; ++i)
    {
        const real3 a = vertices_[i];
        const real3 b = vertices_[i+1];

        const real3 ar = r - a;
        const real3 ab = b - a;

        real alpha = dot(ab, ar) / dot(ab, ab);
        alpha = std::min(1.0_r, std::max(0.0_r, alpha));

        const real3 p = a + alpha * ab;

        const real sdfSegment = length(r - p) - radius_;
        sdfTot = std::min(sdfTot, sdfSegment);
    }

    return insideSign_ * sdfTot;
}

} // namespace sdf
} // namespace sdf_tools
