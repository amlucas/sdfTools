#include "grid.h"

#include <sdf_tools/core/apply_sdf.h>
#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/io/grid.h>

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
                dimensions: Number of cells along each dimension.
                offsets: Start of the domain.
                extents: Size of the domain.
        )")

        .def("get", (std::vector<real>& (Grid::*)()) &Grid::getData, R"(
            Returns a list of all values in a flatten array.
        )")
        .def("get", (const std::vector<real>& (Grid::*)() const) &Grid::getData, R"(
            Returns a list of all values in a flatten array (const).
        )")

        .def("dump", [](const Grid *g, std::string name) {io::dumpGrid(std::move(name), g);},
          "name"_a, R"(
          Dump the data to a file.
          Supported format: .bov, .vtk, .sdf

          Args:
              name: Filename (with the desired extension) to dump to.
        )")

        .def("evaluate_sdf", [](Grid *grid, const sdf::Sdf *sdf) {evaluateAtGridPoints(sdf, grid);})
        .def("evaluate_sdf_periodic", [](Grid *grid, const sdf::Sdf *sdf) {evaluateAtGridPointsPeriodic(sdf, grid);})

        .def("flip", &Grid::flip,
             "map"_a, R"(
          Flip axes of the grid according to map.

          Args:
              map: The flip map description.

          examples:
              * map = 'xyz' does not flip anything
              * map = 'yxz' flip x and y axes
              * map = 'zxy' z -> x, y -> z, x -> y
        )")
        .def("extrude", &Grid::extrude,
             "zoffset"_a, "zextent"_a, "nz"_a, R"(
          Extrude a SDF from 'xy' plane to 3 dimensions.

          Args:
              zoffset: Offset in the new direction.
              zextent: Extent in the new direction.
              nz: Resolution in new direction.
        )");
}

} // namespace sdf_tools
