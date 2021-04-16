#pragma once

#include "sdf_impl.h"

#include <sdf_tools/core/types.h>

namespace sdf_tools {
namespace sdf {

class SdfPlate : public SdfImpl<SdfPlate>
{
public:
    SdfPlate(real3 point, real3 normal);
    SdfPlate(PyReal3 point, PyReal3 normal);

    real at(real3 r) const;

protected:
    real3 point, normal;
};

} // namespace sdf
} // namespace sdf_tools
