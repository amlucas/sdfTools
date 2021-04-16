#pragma once

#include <sdf_tools/core/types.h>

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

namespace detail
{
using ApplyChain = real[];
// in order to suppress warnings
inline void unused(ApplyChain) {}
}

template<typename... Operations>
struct Chain
{
    inline real operator()(real s, real g)
    {
        detail::unused(detail::ApplyChain{ 0.0_r, s = Operations{}(s, g)...});
        return s;
    }
};

} // namespace SdfOperation
