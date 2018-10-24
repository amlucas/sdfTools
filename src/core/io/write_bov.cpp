#include <cstdio>
#include <type_traits>

#include "write_bov.h"

static const char ExtBov[] = ".bov";
static const char ExtVal[] = ".values";

static std::string extract_filename(std::string basename)
{
    auto pos = basename.find_last_of('/');
    if (pos == std::string::npos)
        return basename;

    return std::string(basename.begin() + pos, basename.end());
}

static void write_header(std::string basename, const Grid *grid)
{
    FILE *f = fopen((basename + ExtBov).c_str(), "w");

    auto dim = grid->getDimensions();
    auto off = grid->getOffsets();
    auto ext = grid->getExtents();

    auto val_name = extract_filename(basename) + ExtVal;

    fprintf(f, "DATA_FILE: %s\n", val_name.c_str());
    fprintf(f, "DATA_ENDIAN: %s\n", "LITTLE");
    fprintf(f, "DATA_SIZE: %d %d %d\n", dim.x, dim.y, dim.z);
    fprintf(f, "DATA_FORMAT: %s\n", "FLOAT");
    fprintf(f, "CENTERING: %s\n", "zonal");
    fprintf(f, "BRICK_ORIGIN: %g %g %g\n", off.x, off.y, off.z);
    fprintf(f, "BRICK_SIZE: %g %g %g\n", ext.x, ext.y, ext.z);
    
    fclose(f);
}

static void write_values(std::string basename, const Grid *grid)
{
    FILE *f = fopen((basename + ExtVal).c_str(), "wb");

    auto n = grid->getDimensions();
    
    fwrite((const void*) grid->data(), sizeof(real), n.x * n.y * n.z, f);
    
    fclose(f);
}

void write_bov(std::string basename, const Grid *grid)
{
    write_header(basename, grid);
    write_values(basename, grid);
}
