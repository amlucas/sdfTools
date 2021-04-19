#include "grid.h"

#include <sdf_tools/core/apply_sdf.h>
#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/io/bov.h>
#include <sdf_tools/core/io/custom.h>

#include <pybind11/stl.h>

namespace py = pybind11;
using namespace pybind11::literals;

namespace sdf_tools {

void exportGrid(py::module& m)
{
    py::class_<Grid> (m, "Uniform", R"(
        container to hold SDF grid data

    )")
        .def(py::init <int3, real3, real3> (),
             "dimensions"_a, "offsets"_a, "extents"_a, R"(
            Create an empty uniform grid of given size.

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

        .def("dump_to_bov", [](const Grid *g, std::string basename) {io::writeBov(std::move(basename), g);},
          "basename"_a, R"(
          Dump the data in ``bov`` format

          Args:
              basename: base filename to dump to
        )")
        .def("dump_to_sdf", [](const Grid *g, std::string basename) {io::writeSdf(std::move(basename), g);},
          "basename"_a, R"(
          Dump data in custom ``.sdf`` format

          Args:
              basename: base filename to dump to
        )")

        .def("evaluate_sdf", [](Grid *grid, const sdf::Sdf *sdf) {evaluateAtGridPoints(sdf, grid);})

        .def("flip", &Grid::flip,
             "map"_a, R"(
          flip axes of the grid according to map.

          Args:
              map: flip map

          examples:
              * map = 'xyz' does not flip anything
              * map = 'yxz' flip x and y axes
              * map = 'zxy' z -> x, y -> z, x -> y
        )")
        .def("extrude", &Grid::extrude,
             "zoffset"_a, "zextent"_a, "nz"_a, R"(
          extrude a SDF from 'xy' plane to 3 dimensions

          Args:
              zoffset: offset in new direction
              zextent: extent in new direction
              nz: resolution in new direction
        )");
}

} // namespace sdf_tools
