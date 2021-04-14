#pragma once

#include <iostream>
#include "Coordinates.h"
#include "CarParkTile.h"

class CarParkContainer {
public:
    CarParkContainer();

    CarParkContainer(int height, int width);

    void occupySpot(Coordinates coordinates);

    void emptySpot(Coordinates coordinates);

    void addRow(const std::vector<CarParkTile> &row);

    const std::vector<std::vector<CarParkTile>> &getCarParkTilesMatrix() const;

    unsigned long getHeight() const;

    unsigned long getWidth() const;

    int initCarParkTiles();

    bool isEmptySpot(Coordinates coordinates);

    bool isOccupiedSpot(Coordinates coordinates);

    std::vector<CarParkTile> &operator[](int i);

private:
    std::vector<std::vector<CarParkTile>> carParkTiles;
};
