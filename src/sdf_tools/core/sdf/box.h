#pragma once

#include "sdf.h"

#include <sdf_tools/core/types.h>

namespace sdf_tools {
namespace sdf {

class SdfBox : public Sdf
{
public:
    SdfBox(real3 lowerBound, real3 upperBound, bool inside);

    real at(real3 r) const;

private:
    real3 center_;
    real3 halfExtents_;
    int sign_;
};

} // namespace sdf
} // namespace sdf_tools
