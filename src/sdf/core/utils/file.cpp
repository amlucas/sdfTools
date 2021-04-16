#include "file.h"

#include <sdf/core/utils/error.h>

FILE* safeOpen(const char *fname, const char *mode)
{
    FILE *f = fopen(fname, mode);

    if (!f)
        error("Failed to open '%s' with mode '%s'", fname, mode);

    return f;
}
