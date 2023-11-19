add_library(tren_calatori tren_calatori.cpp)

target_link_libraries(tren_calatori PUBLIC tren)

target_include_directories(tren_calatori PUBLIC
                           ../Tren/
                          )