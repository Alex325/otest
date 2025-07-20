cmake_minimum_required( VERSION 3.15 )

project(OpenGL-test)

if (POLICY CMP0079 )
  cmake_policy(SET CMP0079 NEW)
endif()

add_subdirectory(src)
add_subdirectory(deps/glfw)
add_subdirectory(deps/glad)

target_link_libraries(main glfw glad)

