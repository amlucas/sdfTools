#pragma once

#include "interface.h"

class SdfSphere : public Sdf
{
public:
    SdfSphere(real3 center, real radius, bool inside);
    SdfSphere(PyReal3 center, real radius, bool inside);
    
    void apply(Grid *grid) const override;

    real at(real3 r) const;
    
protected:
    real3 center;
    real radius;
    int sign;
};
