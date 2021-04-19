#include "grid.h"
#include "sdf.h"
#include "types.h"

#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(sdf_tools, m)
{
    sdf_tools::exportVectorTypes(m);

    auto sdf = m.def_submodule("Sdf");
    sdf_tools::exportSdf(sdf);

    auto grid = m.def_submodule("Grid");
    sdf_tools::exportGrid(grid);
}
