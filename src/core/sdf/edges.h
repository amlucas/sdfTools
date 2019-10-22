#pragma once

#include "sdf_impl.h"

#include <core/types.h>

#include <array>
#include <vector>

class SdfEdges : public SdfImpl<SdfEdges>
{
public:
    SdfEdges(const std::vector<real2>& edges, bool inside);
    SdfEdges(const std::vector<std::array<real, 2>>& edges, bool inside);

    real at(real3 r) const;
    
protected:
    std::vector<real2> edges;
    int insideSign;
};
