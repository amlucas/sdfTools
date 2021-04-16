#include "plate.h"

#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/utils/helper_math.h>

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
