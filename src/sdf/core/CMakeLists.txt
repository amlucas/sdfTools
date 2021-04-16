set(SOURCES
  grid.cpp
  )

add_library(sdf SHARED ${SOURCES})

add_subdirectory(io)
add_subdirectory(sdf)
add_subdirectory(utils)

target_compile_features(sdf PUBLIC cxx_std_17)
target_include_directories(sdf PUBLIC ${SDF_INCLUDES})

set_property(TARGET sdf PROPERTY POSITION_INDEPENDENT_CODE ON)
