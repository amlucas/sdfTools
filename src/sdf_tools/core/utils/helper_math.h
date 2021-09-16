#pragma once

#include <sdf_tools/core/types.h>

#include <cmath>

namespace sdf_tools {

inline real3& operator+=(real3 &a, real3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

inline real2& operator+=(real2 &a, real2 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline real3& operator-=(real3 &a, real3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

inline real2& operator-=(real2 &a, real2 b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

inline real3& operator*=(real3 &a, real b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

inline real2& operator*=(real2 &a, real b)
{
    a.x *= b;
    a.y *= b;
    return a;
}

inline real3& operator*=(real3 &a, real3 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

inline real3& operator/=(real3 &a, real b)
{
    const auto s = 1.0_r / b;
    a *= s;
    return a;
}

inline real3& operator/=(real3 &a, real3 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

inline real3& operator/=(real3 &a, int3 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

inline real3 operator+(real3 a, real3 b) { return a += b; }
inline real2 operator+(real2 a, real2 b) { return a += b; }
inline real3 operator-(real3 a, real3 b) { return a -= b; }
inline real2 operator-(real2 a, real2 b) { return a -= b; }
inline real3 operator*(real3 a, real3 b) { return a *= b; }
inline real3 operator/(real3 a, real3 b) { return a /= b; }
inline real3 operator/(real3 a, int3 b) { return a /= b; }
inline real3 operator*(real3 a, real b) { return a *= b; }
inline real2 operator*(real2 a, real b) { return a *= b; }
inline real3 operator*(real a, real3 b) { return b *= a; }
inline real2 operator*(real a, real2 b) { return b *= a; }

inline real dot(real3 a, real3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline real dot(real2 a, real2 b)
{
    return a.x * b.x + a.y * b.y;
}

inline real3 cross(real3 a, real3 b)
{
    return {a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x};
}

inline real cross(real2 a, real2 b)
{
    return a.x * b.y - a.y * b.x;
}

inline real length(real3 a) { return sqrt(dot(a, a)); }
inline real length(real2 a) { return sqrt(dot(a, a));}

} // namespace sdf_tools
