#include "bindings.h"

namespace py = pybind11;

PYBIND11_MODULE(libsdfTools, m)
{
    auto sdf = m.def_submodule("Sdf");
    exportSdf(sdf);
    
    auto grid = m.def_submodule("Grid");
    exportGrid(grid);
}
