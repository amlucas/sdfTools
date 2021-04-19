#include "sdf.h"

#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/sdf/box.h>
#include <sdf_tools/core/sdf/edges.h>
#include <sdf_tools/core/sdf/interface.h>
#include <sdf_tools/core/sdf/plate.h>
#include <sdf_tools/core/sdf/segment.h>
#include <sdf_tools/core/sdf/sphere.h>

#include <pybind11/stl.h>

using namespace pybind11::literals;

namespace sdf_tools {
using namespace sdf;

void exportSdf(py::module& m)
{
    py::class_<Sdf> pysdf(m, "Sdf", R"(
        Base sdf class.
    )");

    pysdf.def("apply", &Sdf::apply,
              "grid"_a, R"(
        Compute the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    )");

    pysdf.def("applyPeriodic", &Sdf::applyPeriodic,
              "grid"_a, R"(
        Compute the given sdf shape and its periodic images for each point of the given grid.

        Args:
            grid: the grid to apply the sdf to
    )");

    pysdf.def("applyComplement", &Sdf::applyComplement,
              "grid"_a, R"(
        Compute the complement of the given sdf shape for each point of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    )");

    pysdf.def("applyComplementPeriodic", &Sdf::applyComplementPeriodic,
              "grid"_a, R"(
        Compute the complement of the given sdf shape and its periodic images for each point
        of the given grid.

        Args:
            grid: the grid to apply the complement sdf to
    )");

    pysdf.def("interiorUnion", &Sdf::interiorUnion,
              "grid"_a, R"(
        Compute the interior union of the given sdf with the given grid.

        Args:
            grid: the grid to apply the union to
    )");

    pysdf.def("interiorUnionPeriodic", &Sdf::interiorUnionPeriodic,
              "grid"_a, R"(
        Compute the interior union of the given sdf and its periodic images with the given grid.

        Args:
            grid: the grid to apply the union to
    )");

    pysdf.def("interiorIntersection", &Sdf::interiorIntersection,
              "grid"_a, R"(
        Compute the interior intersection of the given sdf with the given grid.

        Args:
            grid: the grid to apply the intersection to
    )");

    pysdf.def("interiorIntersectionPeriodic", &Sdf::interiorIntersectionPeriodic,
              "grid"_a, R"(
        Compute the interior intersection of the given sdf and its periodic images
        with the given grid.

        Args:
            grid: the grid to apply the intersection to
    )");

    pysdf.def("interiorSubtractToGrid", &Sdf::interiorSubtractToGrid,
              "grid"_a, R"(
        Compute the interior subtraction of the given grid by the given sdf.

        Args:
            grid: the grid to apply the subtraction to
    )");

    pysdf.def("interiorSubtractToGridPeriodic", &Sdf::interiorSubtractToGridPeriodic,
              "grid"_a, R"(
        Compute the interior subtraction of the given grid by the given sdf and its
        periodic images.

        Args:
            grid: the grid to apply the subtraction to
    )");

    pysdf.def("interiorSubtractGrid", &Sdf::interiorSubtractGrid,
              "grid"_a, R"(
        Compute the interior subtraction of the given sdf by the given grid.

        Args:
            grid: the grid to subtract
    )");

    pysdf.def("interiorSubtractGridPeriodic", &Sdf::interiorSubtractGridPeriodic,
              "grid"_a, R"(
        Compute the interior subtraction of the given sdf and its periodic images by the given
        grid.

        Args:
            grid: the grid to subtract
    )");



    py::class_<SdfBox> (m, "Box", pysdf, R"(
        Box aligned with axes
    )")
        .def(py::init <real3, real3, bool> (),
             "lower_bound"_a, "upper_bound"_a, "inside"_a, R"(

            Args:
                lower_bound: lower corner of the box
                upper_bound: upper corner of the box
                inside: ``True`` if the interior is inside the given shape
        )");

    py::class_<SdfEdges> (m, "Edges", pysdf, R"(
        closed polygon defined from edges
    )")
        .def(py::init <const std::vector<std::array<real, 2>>&, bool, int> (),
             "edges"_a, "inside"_a, "nsamples"_a = 20, R"(

            Args:
                edges: list of vertices positions (2D)
                inside: ``True`` if the interior is inside the given shape
                nsamples: number of samples to find the sign of the SDF (more is more accurate)
        )");

    py::class_<SdfPlate> (m, "Plate", pysdf, R"(
        plate defined by one point and the normal vector

    )")
        .def(py::init <real3, real3> (),
             "point"_a, "normal"_a, R"(
            Args:
                point: one point on the plane
                normal: the normal vector (not necessarily normalized, but must be non-zero)
                        pointing inside
        )");

    py::class_<SdfSegment> (m, "Segment", pysdf, R"(
        segment defined by end points and radius

    )")
        .def(py::init <real3, real3, real, bool> (),
             "start"_a, "end"_a, "radius"_a, "inside"_a, R"(

            Args:
                start: first end of the segment
                end:  second end of the segment
                radius: radius of the segment
                inside: whether the domain is inside the sphere or outside of it
        )");

    py::class_<SdfSphere> (m, "Sphere", pysdf, R"(
        sphere defined by center and radius

    )")
        .def(py::init <real3, real, bool> (),
             "center"_a, "radius"_a, "inside"_a, R"(

            Args:
                center: center of the sphere
                radius: radius of the sphere
                inside: whether the domain is inside the sphere or outside of it
        )");


}

} // namespace sdf_tools
