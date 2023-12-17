cmake_minimum_required(VERSION 3.10)

project(tema1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Tren)

add_executable(tema1 main.cpp)

target_link_libraries(tema1 PUBLIC tren)

target_include_directories(tema1 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/Tren"
                           )
