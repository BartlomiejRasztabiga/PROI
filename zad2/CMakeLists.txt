cmake_minimum_required(VERSION 3.17)
project(zad2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(Chart_run ${SOURCE_FILES})

include_directories(Chart_lib)
add_subdirectory(Chart_lib)

target_link_libraries(Chart_run Chart_lib)

add_subdirectory(Doctest_tests)