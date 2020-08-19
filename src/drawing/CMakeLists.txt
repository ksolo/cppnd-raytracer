add_library(drawing src/canvas.cpp src/ppm_writer.cpp)

target_link_libraries(drawing data_structures)
target_include_directories(drawing PUBLIC include)