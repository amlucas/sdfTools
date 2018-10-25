#include "bindings.h"

#include "core/sdf/interface.h"

#include "core/sdf/sphere.h"
#include "core/sdf/plate.h"

namespace py = pybind11;
using namespace pybind11::literals;

void exportSdf(py::module& m)
{
    py::class_<Sdf> pysdf(m, "Sdf", R"(
        Base sdf class.
    )");

    pysdf.def("apply", &Sdf::apply,
              "grid"_a, R"(
        Compute the given sdf shape for each point of the given grid

        Args:
            grid: the grid to apply the sdf to
    )");

    pysdf.def("applyComplement", &Sdf::applyComplement,
              "grid"_a, R"(
        Compute the complement of the given sdf shape for each point of the given grid

        Args:
            grid: the grid to apply the complement sdf to
    )");
    
    pysdf.def("interiorUnion", &Sdf::interiorUnion,
              "grid"_a, R"(
        Compute the interior union of the given sdf with the given grid

        Args:
            grid: the grid to apply the union to
    )");

    pysdf.def("interiorIntersection", &Sdf::interiorIntersection,
              "grid"_a, R"(
        Compute the interior intersection of the given sdf with the given grid

        Args:
            grid: the grid to apply the intersection to
    )");

    pysdf.def("interiorSubtractToGrid", &Sdf::interiorSubtractToGrid,
              "grid"_a, R"(
        Compute the interior subtraction of the given grid by the given sdf

        Args:
            grid: the grid to apply the subtraction to
    )");

    pysdf.def("interiorSubtractGrid", &Sdf::interiorSubtractGrid,
              "grid"_a, R"(
        Compute the interior subtraction of the given sdf by the given grid

        Args:
            grid: the grid to subtract
    )");


    
    py::class_<SdfSphere> (m, "Sphere", pysdf, R"(
        sphere defined by center and radius

    )")
        .def(py::init <PyReal3, real, bool> (),
             "center"_a, "radius"_a, "inside"_a, R"(
            Args:
                center: center of the sphere
                radius: radius of the sphere
                inside: whether the domain is inside the sphere or outside of it
        )");

    py::class_<SdfPlate> (m, "Plate", pysdf, R"(
        plate defined by one point and the normal vector

    )")
        .def(py::init <PyReal3, PyReal3> (),
             "point"_a, "normal"_a, R"(
            Args:
                point: one point on the plane
                normal: the normal vector (not necessarily normalized, but must be non-zero) pointing inside
        )");


}
