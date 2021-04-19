#pragma once

#include "sdf.h"

#include <sdf_tools/core/types.h>

namespace sdf_tools {
namespace sdf {

class SdfCapsule : public Sdf
{
public:
    SdfCapsule(real3 start, real3 end, real radius, bool inside);

    real at(real3 r) const override;

private:
    real3 start_;
    real3 seg_;
    real radius_;
    real invSegSq_;
    int sign_;
};

} // namespace sdf
} // namespace sdf_tools
