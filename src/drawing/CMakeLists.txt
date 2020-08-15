add_library(drawing src/canvas.cpp)

target_link_libraries(drawing data_structures)
target_include_directories(drawing PUBLIC include)