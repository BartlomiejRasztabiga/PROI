project(Chart)

set(HEADER_FILES CarChart.h)

set(SOURCE_FILES CarChart.cpp)

add_library(Chart_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
