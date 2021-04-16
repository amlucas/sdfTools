pybind11_add_module(pysdf
  bindings.cpp
  grid.cpp
  sdf.cpp)

target_link_libraries(pysdf PUBLIC sdf)
