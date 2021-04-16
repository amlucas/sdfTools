cmake_minimum_required(VERSION 3.8)

if(POLICY CMP0060)
    cmake_policy(SET CMP0060 NEW)
endif()

project(sdf_tools LANGUAGES CXX)

add_subdirectory(src)
