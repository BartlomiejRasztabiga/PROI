// provides main(); this line is required in only one .cpp file
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <CarPark.h>
#include "doctest.h"

TEST_CASE("given new car park, when initEmptyCarPark, then will assign parking spots accordingly") {
    CarPark carPark(6, 5);

    std::vector<std::vector<CarParkTile>> tiles = carPark.getCarParkTilesMatrix();

    CHECK(carPark.getParkingSpotsCount() == 12);
    CHECK(carPark.getAvailableParkingSpotsCount() == 12);
    CHECK(tiles[0] == std::vector<CarParkTile>{CarParkTile::ROAD,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::ROAD});
    CHECK(tiles[1] == std::vector<CarParkTile>{CarParkTile::ROAD,
                                               CarParkTile::ROAD,
                                               CarParkTile::ROAD,
                                               CarParkTile::ROAD,
                                               CarParkTile::ROAD});
    CHECK(tiles[2] == std::vector<CarParkTile>{CarParkTile::ROAD,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::ROAD});
    CHECK(tiles[3] == std::vector<CarParkTile>{CarParkTile::ROAD,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::ROAD});
    CHECK(tiles[4] == std::vector<CarParkTile>{CarParkTile::ROAD,
                                               CarParkTile::ROAD,
                                               CarParkTile::ROAD,
                                               CarParkTile::ROAD,
                                               CarParkTile::ROAD});
    CHECK(tiles[5] == std::vector<CarParkTile>{CarParkTile::ROAD,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::EMPTY_PARKING_SPOT,
                                               CarParkTile::ROAD});
}

TEST_CASE("given new car park, when auto parking car, then will park on next empty space") {
    CarPark carPark(6, 5);

    Coordinates coordinates = carPark.parkCar();

    CHECK((coordinates.x >= 1 && coordinates.x <= 3));
    CHECK((coordinates.y >= 0 && coordinates.y <= 5));
    CHECK(carPark.getCarParkTile(coordinates) == CarParkTile::OCCUPIED_PARKING_SPOT);
}

TEST_CASE("given car park with no spots, when auto parking car, then will throw NoAvailableSpotsException") {
    CarPark carPark(1, 1);
    CHECK_THROWS_AS(carPark.parkCar(), const NoAvailableSpotsException);
}

TEST_CASE("given fully occupied car park, when auto parking car, then will throw NoAvailableSpotsException") {
    CarPark carPark(6, 5);
    std::cout << carPark.getAvailableParkingSpotsCount();

    // park 12 cars
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();
    carPark.parkCar();

    CHECK_THROWS_AS(carPark.parkCar(), const NoAvailableSpotsException);
}

TEST_CASE("given new car park, when parking car at empty parking spot coordinates, then will park a car") {
    CarPark carPark(6, 5);

    carPark.parkCar({1, 0});

    CHECK(carPark.getCarParkTile({1, 0}) == CarParkTile::OCCUPIED_PARKING_SPOT);
}

TEST_CASE(
        "given car park, when parking car at occupied parking spot coordinates, then will throw ParkingSpotOccupiedException") {
    CarPark carPark(6, 5);

    carPark.parkCar({1, 0});

    CHECK_THROWS_AS(carPark.parkCar({1, 0}), const ParkingSpotOccupiedException);
}

TEST_CASE("given car park, when parking car at road coordinates, then will throw NotParkingSpotException") {
    CarPark carPark(6, 5);

    CHECK_THROWS_AS(carPark.parkCar({0, 0}), const NotParkingSpotException);
}

TEST_CASE("given car park with one car, when unparking this car, then will unpark a car") {
    CarPark carPark(6, 5);

    carPark.parkCar({1, 0});
    CHECK(carPark.getAvailableParkingSpotsCount() == 11);
    carPark.unparkCar({1, 0});
    CHECK(carPark.getAvailableParkingSpotsCount() == 12);

    CHECK(carPark.getCarParkTile({1, 0}) == CarParkTile::EMPTY_PARKING_SPOT);
}

TEST_CASE("given empty car park, when unparking from empty spot coordinates, then will throw CarNotFoundException") {
    CarPark carPark(6, 5);

    CHECK_THROWS_AS(carPark.unparkCar({1, 0}), const CarNotFoundException);
}

TEST_CASE("given empty car park, when unparking from road coordinates, then will throw NotParkingSpotException") {
    CarPark carPark(6, 5);

    CHECK_THROWS_AS(carPark.unparkCar({0, 0}), const NotParkingSpotException);
}

TEST_CASE("given empty car park, when get route to spot, then will return route") {
    CarPark carPark(6, 5);

    std::vector<Coordinates> route = carPark.getRouteToParkingSpot({2, 5});

    CHECK(route == std::vector<Coordinates>{{0, 0},
                                            {0, 1},
                                            {0, 2},
                                            {0, 3},
                                            {0, 4},
                                            {1, 4},
                                            {2, 4},
                                            {2, 5}});
}