add_subdirectory(data_structures)
add_subdirectory(drawing)

add_executable(raytracer main.cpp)
target_link_libraries(raytracer PUBLIC data_structures drawing)