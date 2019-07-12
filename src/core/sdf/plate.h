#pragma once

#include "interface.h"
#include "macros.h"

#include <core/types.h>

class SdfPlate : public Sdf
{
public:
    SdfPlate(real3 point, real3 normal);
    SdfPlate(PyReal3 point, PyReal3 normal);
    
    GENERATE_DECL_OPERATIONS()

    real at(real3 r) const;
    
protected:
    real3 point, normal;
};
