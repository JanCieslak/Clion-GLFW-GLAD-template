cmake_minimum_required(VERSION 3.17)
project(Game)

set(CMAKE_CXX_STANDARD 20)

include_directories(includes)
link_directories(lib)

add_executable(Game src/main.cpp src/window.cpp src/window.h src/glad/glad.h src/glad/khrplatform.h src/glad/glad.c)

target_link_libraries(Game glfw3)