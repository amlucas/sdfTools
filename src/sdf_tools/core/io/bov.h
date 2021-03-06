#pragma once

#include <sdf_tools/core/grid.h>

#include <string>

namespace sdf_tools {
namespace io {

void writeBov(std::string basename, const Grid *grid);

} // namespace io
} // namespace sdf_tools
