target_sources(sdf_tools PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/apply_sdf.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/grid.cpp
  )

add_subdirectory(io)
add_subdirectory(sdf)
add_subdirectory(utils)
