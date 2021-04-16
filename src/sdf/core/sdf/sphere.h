#pragma once

#include "sdf_impl.h"

#include <sdf/core/types.h>

class SdfSphere : public SdfImpl<SdfSphere>
{
public:
    SdfSphere(real3 center, real radius, bool inside);
    SdfSphere(PyReal3 center, real radius, bool inside);

    real at(real3 r) const;

protected:
    real3 center;
    real radius;
    int sign;
};
