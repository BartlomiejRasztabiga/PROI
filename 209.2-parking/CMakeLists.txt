cmake_minimum_required(VERSION 3.17)
project(209_2_parking)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(CarPark_run ${SOURCE_FILES})

include_directories(CarPark_lib)
add_subdirectory(CarPark_lib)

target_link_libraries(CarPark_run CarPark_lib)

add_subdirectory(Doctest_tests)