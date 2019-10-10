#pragma once

#include <tuple>

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

using PyInt3 = std::tuple<int, int, int>;
using PyReal2 = std::tuple<real, real>;
using PyReal3 = std::tuple<real, real, real>;

inline int3 make_int3(PyInt3 a)
{
    return {
        std::get<0>(a),
        std::get<1>(a),
        std::get<2>(a)
    };
}

inline real2 make_real2(PyReal2 a)
{
    return {
        std::get<0>(a),
        std::get<1>(a),
    };
}

inline real3 make_real3(PyReal3 a)
{
    return {
        std::get<0>(a),
        std::get<1>(a),
        std::get<2>(a)
    };
}
