#include "sdf.h"

#include <sdf_tools/core/grid.h>
#include <sdf_tools/core/sdf/api.h>

#include <pybind11/stl.h>
#include <memory>

namespace pybind11
{
    template <typename type_, typename... options>
    using shared_class = class_< type_, std::shared_ptr<type_>, options... >;
}


using namespace pybind11::literals;

namespace sdf_tools {
using namespace sdf;

void exportSdf(py::module& m)
{
    py::shared_class<Sdf> pysdf(m, "Sdf", R"(
        Base sdf class.
    )");

    pysdf.def("at", &Sdf::at,
              "r"_a, R"(
        Evaluate the SDF field at the given position.

            Args:
                r: The position where to evaluate the SDF.
    )");

    py::shared_class<SdfBox> (m, "Box", pysdf, R"(
        Box aligned with axes
    )")
        .def(py::init <real3, real3, bool> (),
             "low"_a, "high"_a, "inside"_a, R"(

            Args:
                low: lower corner of the box
                high: upper corner of the box
                inside: ``True`` if the interior is inside the given shape
        )");

    py::shared_class<SdfEdges> (m, "Edges", pysdf, R"(
        closed polygon defined from edges
    )")
        .def(py::init <std::vector<real2>&, bool, int> (),
             "edges"_a, "inside"_a, "nsamples"_a = 20, R"(

            Args:
                edges: list of vertices positions (2D)
                inside: ``True`` if the interior is inside the given shape
                nsamples: number of samples to find the sign of the SDF (more is more accurate)
        )");

    py::shared_class<SdfPlate> (m, "Plate", pysdf, R"(
        Plate defined by one point on the surface and the normal vector, pointing inside.

    )")
        .def(py::init <real3, real3> (),
             "point"_a, "normal"_a, R"(
            Args:
                point: one point on the plane
                normal: the normal vector (not necessarily normalized, but must be non-zero)
                        pointing inside
        )");

    py::shared_class<SdfSegment> (m, "Capsule", pysdf, R"(
        Capsule defined by a segment and a radius.

    )")
        .def(py::init <real3, real3, real, bool> (),
             "start"_a, "end"_a, "radius"_a, "inside"_a, R"(

            Args:
                start: first end of the segment
                end:  second end of the segment
                radius: radius of the capsule
                inside: whether the domain is inside the capsule or outside of it
        )");

    py::shared_class<SdfSphere> (m, "Sphere", pysdf, R"(
        sphere defined by center and radius

    )")
        .def(py::init <real3, real, bool> (),
             "center"_a, "radius"_a, "inside"_a, R"(

            Args:
                center: center of the sphere
                radius: radius of the sphere
                inside: whether the domain is inside the sphere or outside of it
        )");


    py::shared_class<SdfUnion> (m, "Union", pysdf, "Union between two SDF objects.")
        .def(py::init<std::shared_ptr<Sdf>, std::shared_ptr<Sdf>>(),
             "a"_a, "b"_a, R"(

        Args:
            a: The first sdf.
            b: The second sdf.

        )");

    py::shared_class<SdfIntersection> (m, "Intersection", pysdf, "Intersection between two SDF objects.")
        .def(py::init<std::shared_ptr<Sdf>, std::shared_ptr<Sdf>>(),
            "a"_a, "b"_a, R"(

        Args:
            a: The first sdf.
            b: The second sdf.

        )");

    py::shared_class<SdfDifference> (m, "Difference", pysdf, "Difference between two SDF objects.")
        .def(py::init<std::shared_ptr<Sdf>, std::shared_ptr<Sdf>>(),
            "a"_a, "b"_a, R"(

        Args:
            a: The original sdf.
            b: The sdf of the object that should be removed from the original.

        )");


    py::shared_class<SdfComplement> (m, "Complement", pysdf, "Reverse interior and exterior.")
        .def(py::init<std::shared_ptr<Sdf>>(),
            "sdf"_a, R"(

        Args:
            sdf: The original sdf.

        )");

}

} // namespace sdf_tools
