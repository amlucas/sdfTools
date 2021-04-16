#pragma once

#include <core/types.h>

#include <cmath>

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

inline real length(real3 a) { return sqrt(dot(a, a)); }
inline real length(real2 a) { return sqrt(dot(a, a));}

