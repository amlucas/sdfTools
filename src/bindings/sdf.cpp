#include "bindings.h"

#include "core/sdf/interface.h"
#include "core/sdf/sphere.h"

namespace py = pybind11;
using namespace pybind11::literals;

void exportSdf(py::module& m)
{
    // py::class_<Sdf> pysdf(m, "Sdf", R"(
    //     Base sdf class.
    // )");

    py::class_<SdfSphere> (m, "Sphere", R"(
        sphere defined by center and radius

    )")
        .def(py::init <PyReal3, real, bool> (),
             "center"_a, "radius"_a, "inside"_a, R"(
            Args:
                center: center of the sphere
                radius: radius of the sphere
                inside: whether the domain is inside the sphere or outside of it
        )");


}
