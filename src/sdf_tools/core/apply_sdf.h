#pragma once

#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/sdf/api.h>

namespace sdf_tools {

void evaluateAtGridPoints(const sdf::SdfVar& sdfVar, Grid *grid);
void evaluateAtGridPointsPeriodic(const sdf::SdfVar& sdfVar, Grid *grid);


void evaluateAtGridPoints(const sdf::Sdf *sdf, Grid *grid);
void evaluateAtGridPointsPeriodic(const sdf::Sdf *sdf, Grid *grid);

} // namespace sdf_tools
