#pragma once

#include "interface.h"
#include "macros.h"

#include <core/types.h>

class SdfSegment : public Sdf
{
public:
    SdfSegment(real3 start, real3 end, real radius, bool inside);
    SdfSegment(PyReal3 start, PyReal3 end, real radius, bool inside);

    GENERATE_DECL_OPERATIONS()
    
    real at(real3 r) const;
    
protected:
    real3 start, seg;
    real radius, invSegSq;
    int sign;
};
