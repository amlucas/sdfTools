#include "core/types.h"

#include <cmath>

template<typename T3>
real3& operator+=(real3 &a, T3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

template<typename T3>
real3 operator+(real3 a, T3 b)
{
    a += b;
    return a;
}

template<typename T3>
real3& operator-=(real3 &a, T3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

template<typename T3>
real3 operator-(real3 a, T3 b)
{
    a -= b;
    return a;
}

template<typename T3>
real3& operator*=(real3 &a, T3 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

template<typename T3>
real3 operator*(real3 a, T3 b)
{
    a *= b;
    return a;
}

template<typename T3>
real3& operator/=(real3 &a, T3 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

template<typename T3>
real3 operator/(real3 a, T3 b)
{
    a /= b;
    return a;
}

real dot(real3 a, real3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

real length(real3 a)
{
    return sqrt(dot(a, a));
}

