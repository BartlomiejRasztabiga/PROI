cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab1 main.cpp Car.cpp Car.h)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(lab1 PUBLIC DEBUG=1)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(lab1 PUBLIC DEBUG=0)
endif()