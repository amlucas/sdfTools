set(SOURCES
  grid.cpp
  )

add_library(sdf_tools SHARED ${SOURCES})

add_subdirectory(io)
add_subdirectory(sdf)
add_subdirectory(utils)

target_compile_features(sdf_tools PUBLIC cxx_std_17)
target_include_directories(sdf_tools PUBLIC ${SDF_TOOLS_INCLUDES})

set_property(TARGET sdf_tools PROPERTY POSITION_INDEPENDENT_CODE ON)
