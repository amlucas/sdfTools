#pragma once

#include "interface.h"

class SdfPlate : public Sdf
{
public:
    SdfPlate(real3 point, real3 normal);
    SdfPlate(PyReal3 point, PyReal3 normal);
    
    void apply(Grid *grid) const override;

    real at(real3 r) const;
    
protected:
    real3 point, normal;
};
