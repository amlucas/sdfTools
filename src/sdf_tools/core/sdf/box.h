#pragma once

#include "sdf_impl.h"

#include <sdf_tools/core/types.h>

class SdfBox : public SdfImpl<SdfBox>
{
public:
    SdfBox(real3 lowerBound, real3 upperBound, bool inside);
    SdfBox(PyReal3 lowerBound, PyReal3 upperBound, bool inside);

    real at(real3 r) const;

protected:
    real3 center, halfExtents;
    int sign;
};
