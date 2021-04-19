#pragma once

#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/sdf/api.h>

namespace sdf_tools {

void evaluateAtGridPoints(const sdf::SdfVar& sdfVar, Grid *grid);
void evaluateAtGridPointsPeriodic(const sdf::SdfVar& sdfVar, Grid *grid);

} // namespace sdf_tools
