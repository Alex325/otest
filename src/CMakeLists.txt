file(GLOB_RECURSE SRC false ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(main WIN32)

target_compile_definitions(main PRIVATE GLFW_INCLUDE_NONE)

target_sources(main PRIVATE ${SRC})
target_include_directories(main PUBLIC include/)