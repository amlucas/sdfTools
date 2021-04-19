#pragma once

#include "box.h"
#include "capsule.h"
#include "composed.h"
#include "edges.h"
#include "piecewise_pipe.h"
#include "plate.h"
#include "sphere.h"
#include "transformed.h"

#include <variant>

namespace sdf_tools {
namespace sdf {

using SdfVar = std::variant<SdfBox,
                            SdfCapsule,
                            SdfEdges,
                            SdfPiecewisePipe,
                            SdfPlate,
                            SdfSphere>;

} // namespace sdf
} // namespace sdf_tools
