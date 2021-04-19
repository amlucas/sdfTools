#pragma once

#include <sdf_tools/core/types.h>

#include <algorithm>
#include <variant>

namespace sdf_tools {
namespace sdf {
namespace operations {


struct Identity
{
    inline real operator()(real s) const {return s;}
    inline real operator()(real s, real /* g */) const {return s;}
};

struct Complement
{
    inline real operator()(real s) const {return -s;}
    inline real operator()(real s, real /* g */) const {return -s;}
};



struct Union
{
    inline real operator()(real a, real b) const {return std::min(a, b);}
};

struct Intersection
{
    inline real operator()(real a, real b) const {return std::max(a, b);}
};

struct Difference
{
    inline real operator()(real a, real b) const {return std::max(a, -b);}
};


using SdfUnaryOperationVar = std::variant<Identity, Complement>;
using SdfBinaryOperationVar = std::variant<Union, Intersection, Difference>;



// TODO: remove these
struct SubtractToGrid
{
    inline real operator()(real s, real g) const {return std::max(-s, g);}
};

struct SubtractGrid
{
    inline real operator()(real s, real g) const {return std::max(s, -g);}
};




} // namespace operations
} // namespace sdf
} // namespace sdf_tools
