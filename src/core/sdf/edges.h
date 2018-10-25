#pragma once

#include "interface.h"
#include "macros.h"

class SdfEdges : public Sdf
{
public:
    SdfEdges();

    GENERATE_DECL_OPERATIONS()
    
    real at(real3 r) const;
    
protected:
    std::vector<real2> edges;
};
