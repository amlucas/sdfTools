#pragma once

#include "sdf_impl.h"

#include <sdf_tools/core/types.h>

namespace sdf_tools {
namespace sdf {

class SdfSphere : public SdfImpl<SdfSphere>
{
public:
    SdfSphere(real3 center, real radius, bool inside);

    real at(real3 r) const;

protected:
    real3 center;
    real radius;
    int sign;
};

} // namespace sdf
} // namespace sdf_tools
