#pragma once

#include <sdf_tools/core/grid.h>

#include <string>

namespace sdf_tools {
namespace io {

void writeVtk(std::string basename, const Grid *grid);

} // namespace io
} // namespace sdf_tools
