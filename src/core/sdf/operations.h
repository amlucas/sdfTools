#pragma once

#include <algorithm>

namespace SdfOperation
{
struct Identity
{
    inline real operator()(real s)         const {return s;}
    inline real operator()(real s, real g) const {return s;}
};

struct Complement
{
    inline real operator()(real s)         const {return -s;}
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

template<typename... Operations>
struct Chain
{
    inline real operator()(real s, real g)
    {
        using ApplyChain = real[];
        ApplyChain{ s = Operations{}(s, g)...};
        return s;
    }
};

} // namespace SdfOperation
