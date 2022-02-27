cmake_minimum_required(VERSION 3.14)
project(coding C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/SFML)

add_executable(coding src/main.cpp)

target_link_libraries(coding sfml-graphics)
