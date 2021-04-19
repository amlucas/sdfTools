#pragma once

#include <sdf_tools/core/types.h>

#include <algorithm>

namespace sdf_tools {
namespace sdf {
namespace SdfOperation {

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
    inline real operator()(real s, real g) const {return std::min(s, g);}
};

struct Intersection
{
    inline real operator()(real s, real g) const {return std::max(s, g);}
};

struct SubtractToGrid
{
    inline real operator()(real s, real g) const {return std::max(-s, g);}
};

struct SubtractGrid
{
    inline real operator()(real s, real g) const {return std::max(s, -g);}
};

} // namespace SdfOperation
} // namespace sdf
} // namespace sdf_tools
