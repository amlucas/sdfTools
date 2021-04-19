#pragma once

#include "sdf.h"

#include <sdf_tools/core/types.h>

#include <array>
#include <random>
#include <vector>

namespace sdf_tools {
namespace sdf {

class SdfEdges : public Sdf
{
public:
    SdfEdges(std::vector<real2> edges, bool inside, int nsamples);

    real at(real3 r) const;

private:
    real2 findOrigin_();

private:
    std::vector<real2> edges_;
    int insideSign_;
    int nsamples_;
    mutable std::mt19937 gen_{0xC0FFEE};
    real2 origin_;
};

} // namespace sdf
} // namespace sdf_tools
