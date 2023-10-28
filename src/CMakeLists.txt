cmake_minimum_required(VERSION 3.10)

project(tema1)

add_executable(tema1 main.cpp)

add_subdirectory(Tren)

target_include_directories(tema1 Tren)

target_link_directories(tema1 PRIVATE Tren)

target_link_libraries(tema1 tren)