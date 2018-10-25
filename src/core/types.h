#pragma once

#include <tuple>

typedef float real;

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

int3 make_int3(PyInt3 a);
real2 make_real2(PyReal2 a);
real3 make_real3(PyReal3 a);
