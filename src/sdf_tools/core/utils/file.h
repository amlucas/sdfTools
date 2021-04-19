#pragma once

#include <cstdio>

namespace sdf_tools {
namespace utils {

FILE* safeOpen(const char *fname, const char *mode);

} // namespace utils
} // namespace sdf_tools
