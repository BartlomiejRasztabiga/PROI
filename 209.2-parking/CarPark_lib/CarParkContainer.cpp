#include <vector>
#include "CarParkContainer.h"

CarParkContainer::CarParkContainer(int height, int width) :
        carParkTiles(height, std::vector<CarParkTile>(width, CarParkTile::ROAD)) {
}

CarParkContainer::CarParkContainer() = default;

std::vector<CarParkTile> &CarParkContainer::operator[](int i) {
    return this->carParkTiles[i];
}

const std::vector<std::vector<CarParkTile>> &CarParkContainer::getCarParkTilesMatrix() const {
    return this->carParkTiles;
}

void CarParkContainer::addRow(const std::vector<CarParkTile> &row) {
    this->carParkTiles.push_back(row);
}

unsigned long CarParkContainer::getHeight() const {
    return this->carParkTiles.size();
}

unsigned long CarParkContainer::getWidth() const {
    return this->carParkTiles.empty() ? 0 : this->carParkTiles[0].size();
}

void CarParkContainer::occupySpot(Coordinates coordinates) {
    this->carParkTiles[coordinates.y][coordinates.x] = CarParkTile::OCCUPIED_PARKING_SPOT;
}

void CarParkContainer::emptySpot(Coordinates coordinates) {
    this->carParkTiles[coordinates.y][coordinates.x] = CarParkTile::EMPTY_PARKING_SPOT;
}

int CarParkContainer::initCarParkTiles() {
    int parkingSpotsCount = 0;

    for (int rowIndex = 0; rowIndex < this->getHeight(); rowIndex++) {
        for (int columnIndex = 1; columnIndex < this->getWidth() - 1; columnIndex++) {
            // to leave one row of road space
            if (rowIndex % 3 != 1) {
                this->emptySpot({columnIndex, rowIndex});
                parkingSpotsCount++;
            }
        }
    }

    return parkingSpotsCount;
}

bool CarParkContainer::isEmptySpot(Coordinates coordinates) {
    return this->carParkTiles[coordinates.y][coordinates.x] == CarParkTile::EMPTY_PARKING_SPOT;
}

bool CarParkContainer::isOccupiedSpot(Coordinates coordinates) {
    return this->carParkTiles[coordinates.y][coordinates.x] == CarParkTile::OCCUPIED_PARKING_SPOT;;
}
