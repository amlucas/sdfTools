#pragma once

#include <array>

#include "interface.h"
#include "macros.h"

class SdfEdges : public Sdf
{
public:
    SdfEdges(std::vector<real2> edges, bool inside);
    SdfEdges(std::vector<std::array<real, 2>> edges, bool inside);

    GENERATE_DECL_OPERATIONS()
    
    real at(real3 r) const;
    
protected:
    std::vector<real2> edges;
    int insideSign;
};
