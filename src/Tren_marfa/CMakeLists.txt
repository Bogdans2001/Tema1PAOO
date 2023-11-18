add_library(tren_marfa tren_marfa.cpp)

target_link_libraries(tren_marfa PUBLIC tren)

target_include_directories(
                            tren_marfa PUBLIC
                           ../Tren/
)