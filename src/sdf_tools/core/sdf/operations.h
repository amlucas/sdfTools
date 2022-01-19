#pragma once

#include <sdf_tools/core/types.h>

#include <algorithm>
#include <cmath>
#include <variant>

namespace sdf_tools {
namespace sdf {
namespace operations {


struct Complement
{
    real operator()(real s) const {return -s;}
};

using SdfUnaryOperationVar = std::variant<Complement>;




struct Union
{
    real operator()(real a, real b) const {return std::min(a, b);}
};

struct Intersection
{
    real operator()(real a, real b) const {return std::max(a, b);}
};

struct Difference
{
    real operator()(real a, real b) const {return std::max(a, -b);}
};

struct SmoothUnion
{
    SmoothUnion(real k=32.0_r) :
        k_{k}
    {}

    real operator()(real a, real b) const
    {
        constexpr real eps {1e-6_r};
        const real res = std::exp(-k_ * a) + std::exp(-k_ * b);

        return -std::log(std::max(eps, res)) / k_;
    }

private:
    real k_;
};

using SdfBinaryOperationVar = std::variant<Union, Intersection, Difference, SmoothUnion>;


} // namespace operations
} // namespace sdf
} // namespace sdf_tools
