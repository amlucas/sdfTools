#include "apply_sdf.h"

#include <sdf_tools/core/sdf/operations.h>

namespace sdf_tools {

void evaluateAtGridPoints(const sdf::Sdf *sdf, Grid *grid)
{
    auto applySdf = [sdf](real3 r, real& gridValue) {gridValue = sdf->at(r);};
    gridForEachPoint(applySdf, grid);
}

void evaluateAtGridPointsPeriodic(const sdf::Sdf *sdf, Grid *grid)
{
    const real3 extents = grid->getExtents();
    auto applySdfPeriodic = [sdf,extents](real3 r, real& gridValue)
    {
        real s = sdf->at(r);

        for (int dz = -1; dz <= 1; ++dz) {
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dz == 0 && dy == 0 && dx == 0)
                        continue;

                    const real3 rImage {r.x + dx * extents.x,
                                        r.y + dy * extents.y,
                                        r.z + dz * extents.z};

                    s = sdf::operations::Union{}(s, sdf->at(rImage));
                }
            }
        }

        gridValue = sdf->at(r);
    };

    gridForEachPoint(applySdfPeriodic, grid);
}


} // namespace sdf_tools
