#pragma once

#include "sdf.h"

#include <sdf_tools/core/types.h>

namespace sdf_tools {
namespace sdf {

class SdfSphere : public Sdf
{
public:
    SdfSphere(real3 center, real radius, bool inside);

    real at(real3 r) const override;

private:
    real3 center_;
    real radius_;
    int sign_;
};

} // namespace sdf
} // namespace sdf_tools
