#pragma once

#include "interface.h"
#include "macros.h"

#include <core/types.h>

class SdfBox : public Sdf
{
public:
    SdfBox(real3 lowerBound, real3 upperBound, bool inside);
    SdfBox(PyReal3 lowerBound, PyReal3 upperBound, bool inside);

    GENERATE_DECL_OPERATIONS()
    
    real at(real3 r) const;
    
protected:
    real3 center, halfExtents;
    int sign;
};
