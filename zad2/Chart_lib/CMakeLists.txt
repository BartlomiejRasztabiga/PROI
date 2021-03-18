project(Chart)

set(HEADER_FILES Chart.h)

set(SOURCE_FILES Chart.cpp)

add_library(Chart_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
