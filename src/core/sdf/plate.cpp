#include "plate.h"
#include "common.h"

#include <core/grid.h>
#include <core/utils/helper_math.h>

SdfPlate::SdfPlate(real3 point, real3 normal) :
    point(point), normal(normal)
{
    real nrm = length(normal);
    normal *= (real(1.0) / nrm);
}

SdfPlate::SdfPlate(PyReal3 point, PyReal3 normal) :
    SdfPlate(make_real3(point), make_real3(normal))
{}

real SdfPlate::at(real3 r) const
{
    real3 dr = r - point;
    return -dot(dr, normal);
}

#define CLASS_NAME SdfPlate
GENERATE_IMPL_OPERATIONS()
