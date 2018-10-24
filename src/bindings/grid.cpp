#include "bindings.h"

#include "core/grid.h"
#include "core/io/write_bov.h"

namespace py = pybind11;
using namespace pybind11::literals;

void exportGrid(py::module& m)
{
    py::class_<Grid> (m, "Uniform", R"(
        container to hold sdf grid data

    )")
        .def(py::init <PyInt3, PyReal3, PyReal3> (),
             "dimensions"_a, "offsets"_a, "extents"_a, R"(
            Args:
                dimensions: number of cells along each dimension
                offsets: start of the domain
                extents: size of the domain
        )")
        .def("get", &Grid::getData);

    m.def("write_bov", &write_bov,
          "basename"_a, "grid"_a, R"(
          Args:
              basename: base filename to dump to
              grid: grid data to dump
          )");
}
