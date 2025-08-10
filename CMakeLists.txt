cmake_minimum_required(VERSION 4.0)

project(OpenGL-test)

add_subdirectory(src)
add_subdirectory(deps/glfw)
add_subdirectory(deps/glad)

target_link_libraries(main glfw glad)

add_compile_options(-O3 -flto -Wall)

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out")