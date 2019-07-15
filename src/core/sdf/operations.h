#pragma once

#include <algorithm>

namespace SdfOperation
{
struct Identity
{
    inline real operator()(real s, real g) const {return s;}
};

struct Complement
{
    inline real operator()(real s, real g) const {return -s;}
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
