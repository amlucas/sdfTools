#pragma once

#include "box.h"
#include "edges.h"
#include "plate.h"
#include "segment.h"
#include "sphere.h"

#include <variant>

namespace sdf_tools {
namespace sdf {

using SdfVar = std::variant<SdfBox,
                            SdfEdges,
                            SdfPlate,
                            SdfSegment,
                            SdfSphere>;

} // namespace sdf
} // namespace sdf_tools
