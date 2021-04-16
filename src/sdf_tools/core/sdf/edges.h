#pragma once

#include "sdf_impl.h"

#include <sdf_tools/core/types.h>

#include <array>
#include <random>
#include <vector>

class SdfEdges : public SdfImpl<SdfEdges>
{
public:
    SdfEdges(const std::vector<real2>& edges, bool inside, int nsamples);
    SdfEdges(const std::vector<std::array<real,2>>& edges, bool inside, int nsamples);

    real at(real3 r) const;

protected:
    real2 findOrigin();

protected:
    std::vector<real2> edges;
    int insideSign;
    int nsamples;
    mutable std::mt19937 gen{424242L};
    real2 origin;
};