cmake_minimum_required(VERSION 3.16)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

# SETUP GTEST
add_subdirectory(${CMAKE_SOURCE_DIR}/vendor/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(tests)
