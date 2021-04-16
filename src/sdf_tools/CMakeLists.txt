pybind11_add_module(sdf_tools)

add_subdirectory(core)
add_subdirectory(bindings)

target_compile_features(sdf_tools PUBLIC cxx_std_17)
target_include_directories(sdf_tools PUBLIC ${SDF_TOOLS_INCLUDES})
set_property(TARGET sdf_tools PROPERTY POSITION_INDEPENDENT_CODE ON)

target_compile_options(sdf_tools PRIVATE -O3 -Wall -Wextra)
