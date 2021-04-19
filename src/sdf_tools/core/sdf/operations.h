#pragma once

#include <sdf_tools/core/types.h>

#include <algorithm>
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

using SdfBinaryOperationVar = std::variant<Union, Intersection, Difference>;


} // namespace operations
} // namespace sdf
} // namespace sdf_tools
