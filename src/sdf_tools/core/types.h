#pragma once

namespace sdf_tools {

typedef float real;

constexpr inline real operator "" _r (const long double a)
{
    return (real) a;
}

struct int3
{
    int x, y, z;
};

struct real2
{
    real x, y;
};

struct real3
{
    real x, y, z;
};

} // namespace sdf_tools
