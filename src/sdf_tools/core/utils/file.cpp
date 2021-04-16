#include "file.h"

#include <sdf_tools/core/utils/error.h>

namespace sdf_tools {
namespace utils {

FILE* safeOpen(const char *fname, const char *mode)
{
    FILE *f = fopen(fname, mode);

    if (!f)
        error("Failed to open '%s' with mode '%s'", fname, mode);

    return f;
}

} // namespace utils
} // namespace sdf_tools
