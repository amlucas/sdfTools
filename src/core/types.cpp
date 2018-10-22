#include "types.h"

int3 make_int3(PyInt3 a)
{
    return {
        std::get<0>(a),
        std::get<1>(a),
        std::get<2>(a)
    };
}

real3 make_real3(PyReal3 a)
{
    return {
        std::get<0>(a),
        std::get<1>(a),
        std::get<2>(a)
    };
}
