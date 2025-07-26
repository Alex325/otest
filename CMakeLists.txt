cmake_minimum_required(VERSION 4.0)

project(OpenGL-test)

add_subdirectory(src)
add_subdirectory(deps/glfw)
add_subdirectory(deps/glad)

target_link_libraries(main glfw glad)


