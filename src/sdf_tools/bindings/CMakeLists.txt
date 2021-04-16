pybind11_add_module(pysdftools
  bindings.cpp
  grid.cpp
  sdf.cpp)

target_link_libraries(pysdftools PUBLIC sdf_tools)
