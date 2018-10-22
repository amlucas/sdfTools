#include "bindings.h"

#include "core/sdf/interface.h"
#include "core/sdf/sphere.h"

namespace py = pybind11;
using namespace pybind11::literals;

void exportGrid(py::module& m)
{
    py::class_<Grid> (m, "Grid", R"(
        container to hold sdf grid data

    )")
        .def(py::init <PyInt3, PyReal3, PyReal3> (),
             "dimensions"_a, "offsets"_a, "extents"_a, R"(
            Args:
                dimensions: number of cells along each dimension
                offsets: start of the domain
                extents: size of the domain
        )");
}
