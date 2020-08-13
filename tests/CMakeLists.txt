add_executable(run_tests
    data_structures/tuple_test.cpp
    data_structures/color_test.cpp
    drawing/canvas_test.cpp
)
target_link_libraries(run_tests gtest gtest_main data_structures drawing)
