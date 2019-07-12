#pragma once

#include "interface.h"
#include "macros.h"

#include <core/types.h>

class SdfSphere : public Sdf
{
public:
    SdfSphere(real3 center, real radius, bool inside);
    SdfSphere(PyReal3 center, real radius, bool inside);

    GENERATE_DECL_OPERATIONS()
    
    real at(real3 r) const;
    
protected:
    real3 center;
    real radius;
    int sign;
};
