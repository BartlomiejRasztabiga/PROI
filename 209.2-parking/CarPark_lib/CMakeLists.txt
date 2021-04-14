project(CarPark)

set(HEADER_FILES Car.h CarPark.h CarParkGui.h CarParkContainer.h Coordinates.h CarParkTile.h)

set(SOURCE_FILES Car.cpp CarPark.cpp CarParkGui.cpp CarParkContainer.cpp)

add_library(CarPark_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
