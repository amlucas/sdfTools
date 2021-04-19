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

protected:
    real3 center, halfExtents;
    int sign;
};

} // namespace sdf
} // namespace sdf_tools
