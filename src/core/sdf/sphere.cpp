#include "sphere.h"
#include "core/utils/helper_math.h"

SdfSphere::SdfSphere(real3 center, real radius, bool inside) :
    center(center), radius(radius),
    sign(inside ? 1 : -1)
{}

void SdfSphere::apply(Grid *grid) const
{
    auto dims = grid->getDimensions();
    auto exts = grid->getExtents();
    auto offs = grid->getOffsets();
    real *data = grid->data();

    real3 d;
    d.x = exts.x / dims.x;
    d.y = exts.y / dims.y;
    d.z = exts.z / dims.z;

    for (int iz = 0; iz < dims.z; ++iz)
        for (int iy = 0; iy < dims.y; ++iy)
            for (int ix = 0; ix < dims.x; ++ix) {
                real3 r;
                r.x = offs.x + ix * d.x;
                r.y = offs.y + iy * d.y;
                r.z = offs.z + iz * d.z;

                data[ix + dims.x * (iy + dims.y * iz)] = _sdf(r);
            }
}

real SdfSphere::_sdf(real3 r) const
{
    return sign * (length(r - center) - radius);
}
