#pragma once

#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/sdf/sdf.h>

namespace sdf_tools {

void evaluateAtGridPoints(const sdf::Sdf *sdf, Grid *grid);
void evaluateAtGridPointsPeriodic(const sdf::Sdf *sdf, Grid *grid);

} // namespace sdf_tools
