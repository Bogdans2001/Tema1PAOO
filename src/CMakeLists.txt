cmake_minimum_required(VERSION 3.10)

project(tema1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Tren)

add_subdirectory(Tren_calatori)

add_subdirectory(Tren_marfa)

add_executable(tema1 main.cpp)

target_link_libraries(tema1 PUBLIC tren)

target_link_libraries(tema1 PUBLIC tren_calatori)

target_link_libraries(tema1 PUBLIC tren_marfa)

target_include_directories(tema1 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/Tren"
                           )

target_include_directories(tema1 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/Tren_calatori"
                           )

target_include_directories(tema1 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/Tren_marfa"
                           )