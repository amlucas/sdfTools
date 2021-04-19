#pragma once

#include "sdf.h"

#include <sdf_tools/core/types.h>

namespace sdf_tools {
namespace sdf {

class SdfPlate : public Sdf
{
public:
    SdfPlate(real3 point, real3 normal);

    real at(real3 r) const override;

private:
    real3 point_;
    real3 normal_;
};

} // namespace sdf
} // namespace sdf_tools
