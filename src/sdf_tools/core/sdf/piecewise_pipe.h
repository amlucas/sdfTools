#pragma once

#include "sdf.h"

#include <sdf_tools/core/types.h>

#include <vector>

namespace sdf_tools {
namespace sdf {

class SdfPiecewisePipe : public Sdf
{
public:
    SdfPiecewisePipe(std::vector<real3> vertices, real radius, bool inside);

    real at(real3 r) const;

private:
    std::vector<real3> vertices_;
    real radius_;
    int insideSign_;
};

} // namespace sdf
} // namespace sdf_tools
