cmake_minimum_required(VERSION 3.8)

if(POLICY CMP0060)
    cmake_policy(SET CMP0060 NEW)
endif()

project(sdfTools LANGUAGES CXX)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(SDF "libsdfTools")

# Add the pybind11
add_subdirectory(src/extern/pybind11)

# Require c++11
set(CMAKE_CXX_STANDARD  11)

# Alias some dirs
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src/ )
set(CORE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/core/")
set(BINDINGS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/bindings/")
set(PYTHON_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/sdfTools")

# Find sources
file(GLOB_RECURSE SOURCES_BINDINGS  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${BINDINGS_DIR}/*.cpp")
file(GLOB_RECURSE SOURCES_MAIN      RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CORE_DIR}/*.cpp")

# Define the main executable
#add_executable(udevicex ../apps/udevicex/main.cu ${CXX_SOURCES} ${CUDA_SOURCES})
add_library(main_compiled OBJECT ${SOURCES_MAIN})
set_property(TARGET main_compiled PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(${SDF} MODULE ${SOURCES_BINDINGS} $<TARGET_OBJECTS:main_compiled>)
target_link_libraries(${SDF} PRIVATE pybind11::module)
set_target_properties(${SDF} PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
                                        SUFFIX "${PYTHON_MODULE_EXTENSION}")

# Setup compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -Wall -fvisibility=hidden")

# Linker flags
set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -fvisibility=hidden")

# Choose Release mode as default.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()
