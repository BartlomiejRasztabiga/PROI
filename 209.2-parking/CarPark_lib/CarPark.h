#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include "CarParkContainer.h"
#include "Coordinates.h"
#include "CarParkTile.h"

struct NoAvailableSpotsException : public std::exception {
    const char *what() const noexcept override {
        return "There are no more available spots.";
    }
};

struct CarNotFoundException : public std::exception {
    const char *what() const noexcept override {
        return "There is no car at given coordinates.";
    }
};

struct NotParkingSpotException : public std::exception {
    const char *what() const noexcept override {
        return "There is no parking spot at given coordinates.";
    }
};

struct ParkingSpotOccupiedException : public std::exception {
    const char *what() const noexcept override {
        return "The parking spot at given coordinates is already occupied.";
    }
};

class CarPark {
public:
    CarPark(int height, int width);

    CarPark();

    Coordinates parkCar();

    void parkCar(Coordinates coordinates);

    void unparkCar(Coordinates coordinates);

    Coordinates findNextAvailableSpot();

    std::vector<Coordinates> getRouteToParkingSpot(Coordinates coordinates);

    int getAvailableParkingSpotsCount() const;

    int getParkingSpotsCount() const;

    unsigned long getHeight() const;

    unsigned long getWidth() const;

    CarParkTile getCarParkTile(Coordinates coordinates);

    const std::vector<std::vector<CarParkTile>> &getCarParkTilesMatrix() const;

    friend std::ostream &operator<<(std::ostream &out, const CarPark &carPark);

    friend std::istream &operator>>(std::istream &in, CarPark &carPark);

private:
    CarParkContainer carParkContainer;
    int parkingSpotsCount;
    int availableParkingSpotsCount;

    void initEmptyCarPark();

    bool isEmptyParkingSpot(Coordinates coordinates);

    bool isOccupiedParkingSpot(Coordinates coordinates);

    void addCarParkTilesRow(const std::vector<CarParkTile> &row);
};
