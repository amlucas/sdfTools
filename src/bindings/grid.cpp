#include "bindings.h"

#include "core/grid.h"
#include "core/io/write_bov.h"

namespace py = pybind11;
using namespace pybind11::literals;

void exportGrid(py::module& m)
{
    py::class_<Grid> (m, "Uniform", R"(
        container to hold SDF grid data

    )")
        .def(py::init <PyInt3, PyReal3, PyReal3> (),
             "dimensions"_a, "offsets"_a, "extents"_a, R"(
            Args:
                dimensions: number of cells along each dimension
                offsets: start of the domain
                extents: size of the domain
        )")

        .def("get", (std::vector<real>& (Grid::*)()) &Grid::getData, R"(
            returns a list of all values in a flatten array.
        )")
        .def("get", (const std::vector<real>& (Grid::*)() const) &Grid::getData, R"(
            returns a list of all values in a flatten array (const).
        )")
        
        .def("dumpBov", &Grid::dumpBov,
          "basename"_a, R"(
          Dump the data in ``bov`` format
          Args:
              basename: base filename to dump to
        )")
        .def("dumpSdf", &Grid::dumpSdf,
          "basename"_a, R"(
          Dump data in custom ``.sdf`` format
          Args:
              basename: base filename to dump to
        )")

        .def("applySdfComplement", &Grid::applySdfComplement,
          R"(
          apply complement unary operation 
        )")
        .def("applySdfInteriorUnion", &Grid::applySdfInteriorUnion,
             "other"_a, R"(
          apply interior union between this grid and another given grid 
          Args:
              other: the other grid 
        )")
        .def("applySdfInteriorIntersection", &Grid::applySdfInteriorIntersection,
             "other"_a, R"(
          apply interior intersection between this grid and another given grid 
          Args:
              other: the other grid 
        )")
        .def("applySdfSubtract", &Grid::applySdfSubtract,
             "other"_a, R"(
          apply interior subtract between this grid and another given grid 
          Args:
              other: the other grid 
        )");
}
