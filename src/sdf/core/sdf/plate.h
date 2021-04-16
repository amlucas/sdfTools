#pragma once

#include "sdf_impl.h"

#include <sdf/core/types.h>

class SdfPlate : public SdfImpl<SdfPlate>
{
public:
    SdfPlate(real3 point, real3 normal);
    SdfPlate(PyReal3 point, PyReal3 normal);

    real at(real3 r) const;

protected:
    real3 point, normal;
};
