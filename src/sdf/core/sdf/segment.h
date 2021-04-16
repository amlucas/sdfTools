#pragma once

#include "sdf_impl.h"

#include <sdf/core/types.h>

class SdfSegment : public SdfImpl<SdfSegment>
{
public:
    SdfSegment(real3 start, real3 end, real radius, bool inside);
    SdfSegment(PyReal3 start, PyReal3 end, real radius, bool inside);

    real at(real3 r) const;

protected:
    real3 start, seg;
    real radius, invSegSq;
    int sign;
};
