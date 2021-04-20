#include "grid.h"
#include "bov.h"
#include "custom.h"
#include "vtk.h"

#include <sdf_tools/core/utils/error.h>

#include <tuple>

namespace sdf_tools {
namespace io {

std::tuple<std::string, std::string> splitExtension(std::string name)
{
    auto pos = name.rfind('.');
    sdfToolsExpect(pos != std::string::npos, "Could not find extension of '%s'", name.c_str());

    return {name.substr(0, pos),
            name.substr(pos+1)};
}

void dumpGrid(std::string name, const Grid *grid)
{
    const auto [basename, extension]  = splitExtension(name);

    if (extension == "bov")
    {
        writeBov(basename, grid);
    }
    else if (extension == "sdf")
    {
        writeSdf(basename, grid);
    }
    else if (extension == "vtk")
    {
        writeVtk(basename, grid);
    }
    else
    {
        sdfToolsDie("extension '%s' is not supported.", extension.c_str());
    }
}

} // namespace io
} // namespace sdf_tools
