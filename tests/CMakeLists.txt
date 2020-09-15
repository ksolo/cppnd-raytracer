add_executable(run_tests
    data_structures/tuple_test.cpp
    data_structures/color_test.cpp
    data_structures/matrix_test.cpp
    drawing/canvas_test.cpp
    drawing/ppm_writer_test.cpp
)
target_link_libraries(run_tests gtest gtest_main data_structures drawing)
