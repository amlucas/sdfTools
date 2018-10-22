#pragma once

#include <tuple>

typedef float real;

struct int3
{
    int x, y, z;
};

struct real3
{
    real x, y, z;
};

using PyInt3 = std::tuple<int, int, int>;
using PyReal3 = std::tuple<real, real, real>;

int3 make_int3(PyInt3 a);
real3 make_real3(PyReal3 a);
