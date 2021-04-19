#pragma once

#include "sdf.h"

#include <sdf_tools/core/types.h>

namespace sdf_tools {
namespace sdf {

class SdfSegment : public Sdf
{
public:
    SdfSegment(real3 start, real3 end, real radius, bool inside);

    real at(real3 r) const override;

protected:
    real3 start, seg;
    real radius, invSegSq;
    int sign;
};

} // namespace sdf
} // namespace sdf_tools
