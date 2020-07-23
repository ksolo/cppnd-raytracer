project(tests)

add_subdirectory(${CMAKE_SOURCE_DIR}/tests/vendor/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(run_tests ExampleTest.cpp)
target_link_libraries(run_tests gtest gtest_main)