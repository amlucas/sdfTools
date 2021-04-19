#include "types.h"

#include <sdf_tools/core/types.h>

#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace sdf_tools {

namespace py = pybind11;
using namespace pybind11::literals;

void exportVectorTypes(py::module &m)
{
    PYBIND11_NUMPY_DTYPE(real2, x, y);
    py::class_<real2>(m, "real2")
        .def(py::init<real, real>(), "x"_a, "y"_a)
        .def(py::init([](py::tuple t) {
                          if (py::len(t) != 2)
                              throw std::runtime_error("Should have length 2.");
                          return real2{t[0].cast<real>(), t[1].cast<real>()};
                      }))
        .def(py::init([](py::list t) {
                          if (py::len(t) != 2)
                              throw std::runtime_error("Should have length 2.");
                          return real2{t[0].cast<real>(), t[1].cast<real>()};
                      }))
        .def_readwrite("x", &real2::x)
        .def_readwrite("y", &real2::y)
        .def("__getitem__",
             [](const real2 &v, size_t i) {
                 if (i == 0) return v.x;
                 if (i == 1) return v.y;
                 throw py::index_error();
                 return 0._r;
             })
        .def("__str__", [](const real2 &v) { return "({}, {})"_s.format(v.x, v.y); })
        .def("__repr__",
             [](const real2 &v) { return "real2({}, {})"_s.format(v.x, v.y); });

    py::implicitly_convertible<py::tuple, real2>();
    py::implicitly_convertible<py::list, real2>();



    PYBIND11_NUMPY_DTYPE(real3, x, y, z);
    py::class_<real3>(m, "real3")
        .def(py::init<real, real, real>(), "x"_a, "y"_a, "z"_a)
        .def(py::init([](py::tuple t) {
                          if (py::len(t) != 3)
                              throw std::runtime_error("Should have length 3.");
                          return real3{t[0].cast<real>(), t[1].cast<real>(), t[2].cast<real>()};
                      }))
        .def(py::init([](py::list t) {
                          if (py::len(t) != 3)
                              throw std::runtime_error("Should have length 3.");
                          return real3{t[0].cast<real>(), t[1].cast<real>(), t[2].cast<real>()};
                      }))
        .def_readwrite("x", &real3::x)
        .def_readwrite("y", &real3::y)
        .def_readwrite("z", &real3::z)
        .def("__getitem__",
             [](const real3 &v, size_t i) {
                 if (i == 0) return v.x;
                 if (i == 1) return v.y;
                 if (i == 2) return v.z;
                 throw py::index_error();
                 return 0._r;
             })
        .def("__str__", [](const real3 &v) { return "({}, {}, {})"_s.format(v.x, v.y, v.z); })
        .def("__repr__",
             [](const real3 &v) { return "real3({}, {}, {})"_s.format(v.x, v.y, v.z); });

    py::implicitly_convertible<py::tuple, real3>();
    py::implicitly_convertible<py::list, real3>();


    PYBIND11_NUMPY_DTYPE(int3, x, y, z);
    py::class_<int3>(m, "int3")
        .def(py::init<int, int, int>(), "x"_a, "y"_a, "z"_a)
        .def(py::init([](py::tuple t) {
                          if (py::len(t) != 3) throw std::runtime_error("Should have length 3.");
                          return int3{t[0].cast<int>(), t[1].cast<int>(), t[2].cast<int>()};
                      }))
        .def(py::init([](py::list t) {
                          if (py::len(t) != 3) throw std::runtime_error("Should have length 3.");
                          return int3{t[0].cast<int>(), t[1].cast<int>(), t[2].cast<int>()};
                      }))
        .def_readwrite("x", &int3::x)
        .def_readwrite("y", &int3::y)
        .def_readwrite("z", &int3::z)
        .def("__getitem__",
             [](const int3 &v, size_t i) {
                 if (i == 0) return v.x;
                 if (i == 1) return v.y;
                 if (i == 2) return v.z;
                 throw py::index_error();
                 return 0;
             })
        .def("__str__", [](const int3 &v) { return "({}, {}, {})"_s.format(v.x, v.y, v.z); })
        .def("__repr__",
             [](const int3 &v) { return "int3({}, {}, {})"_s.format(v.x, v.y, v.z); });

    py::implicitly_convertible<py::tuple, int3>();
    py::implicitly_convertible<py::list, int3>();
}

} // namespace sdf_tools
