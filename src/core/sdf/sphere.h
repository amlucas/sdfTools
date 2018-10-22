#pragma once

#include "interface.h"

class SdfSphere : public Sdf
{
public:
    SdfSphere(real3 center, real radius, bool inside);

    void apply(Grid *grid) const override;
    
protected:
    real3 center;
    real radius;
    int sign;

    real _sdf(real3 r) const;
};
