#include "CarPark.h"


CarPark::CarPark(int height, int width) :
        parkingSpotsCount(0),
        availableParkingSpotsCount(0),
        carParkContainer(height, width) {
    this->initEmptyCarPark();
}

CarPark::CarPark() :
        parkingSpotsCount(0),
        availableParkingSpotsCount(0) {
}


std::ostream &operator<<(std::ostream &out, const CarPark &carPark) {
    for (const std::vector<CarParkTile> &row : carPark.getCarParkTilesMatrix()) {
        for (CarParkTile tile : row) {
            out << static_cast<int>(tile) << " ";
        }
        out << std::endl;
    }

    return out;
}

std::istream &operator>>(std::istream &in, CarPark &carPark) {
    for (std::string line; getline(in, line);) {
        std::stringstream stream(line);
        std::vector<CarParkTile> row;
        std::string tmp;
        while (getline(stream, tmp, ' ')) {
            row.push_back(static_cast<CarParkTile>(std::stoi(tmp)));
        }
        carPark.addCarParkTilesRow(row);
    }

    return in;
}

const std::vector<std::vector<CarParkTile>> &CarPark::getCarParkTilesMatrix() const {
    return this->carParkContainer.getCarParkTilesMatrix();
}

Coordinates CarPark::parkCar() {
    if (this->availableParkingSpotsCount == 0) {
        throw NoAvailableSpotsException();
    }

    Coordinates availableSpot = this->findNextAvailableSpot();
    this->carParkContainer.occupySpot(availableSpot);
    this->availableParkingSpotsCount--;

    return availableSpot;
}

void CarPark::parkCar(Coordinates coordinates) {
    if (this->isEmptyParkingSpot(coordinates)) {
        this->carParkContainer.occupySpot(coordinates);
        this->availableParkingSpotsCount--;
    } else if (this->isOccupiedParkingSpot(coordinates)) {
        throw ParkingSpotOccupiedException();
    } else {
        throw NotParkingSpotException();
    }
}

void CarPark::unparkCar(Coordinates coordinates) {
    if (this->isOccupiedParkingSpot(coordinates)) {
        this->carParkContainer.emptySpot(coordinates);
        this->availableParkingSpotsCount++;
    } else if (this->isEmptyParkingSpot(coordinates)) {
        throw CarNotFoundException();
    } else {
        throw NotParkingSpotException();
    }
}

void CarPark::addCarParkTilesRow(const std::vector<CarParkTile> &row) {
    this->carParkContainer.addRow(row);

    for (CarParkTile tile : row) {
        if (tile == CarParkTile::EMPTY_PARKING_SPOT) {
            this->availableParkingSpotsCount++;
            this->parkingSpotsCount++;
        } else if (tile == CarParkTile::OCCUPIED_PARKING_SPOT) {
            this->parkingSpotsCount++;
        }
    }
}

Coordinates CarPark::findNextAvailableSpot() {
    for (int rowIndex = 0; rowIndex < this->getHeight(); rowIndex++) {
        for (int columnIndex = 1; columnIndex < this->getWidth() - 1; columnIndex++) {
            // one row of road space
            if (rowIndex % 3 != 1) {
                if (this->isEmptyParkingSpot({columnIndex, rowIndex})) {
                    return {columnIndex, rowIndex};
                }
            }
        }
    }

    throw NoAvailableSpotsException();
}

std::vector<Coordinates> CarPark::getRouteToParkingSpot(Coordinates coordinates) {
    if (this->isOccupiedParkingSpot(coordinates) || this->isEmptyParkingSpot(coordinates)) {
        std::vector<Coordinates> route;
        // assuming (0, 0) is the entrance and is ROAD
        int roadRow = ((int) coordinates.y / 3) * 3 + 1;
        for (int i = 0; i <= roadRow; i++) {
            route.push_back({0, i});
        }

        for (int i = 1; i <= coordinates.x; ++i) {
            route.push_back({i, roadRow});
        }

        route.push_back(coordinates);

        return route;
    } else {
        throw NotParkingSpotException();
    }
}

unsigned long CarPark::getHeight() const {
    return this->carParkContainer.getHeight();
}

unsigned long CarPark::getWidth() const {
    return this->carParkContainer.getWidth();
}

int CarPark::getAvailableParkingSpotsCount() const {
    return this->availableParkingSpotsCount;
}

int CarPark::getParkingSpotsCount() const {
    return this->parkingSpotsCount;
}

CarParkTile CarPark::getCarParkTile(Coordinates coordinates) {
    return this->carParkContainer[coordinates.y][coordinates.x];
}

void CarPark::initEmptyCarPark() {
    this->parkingSpotsCount = this->carParkContainer.initCarParkTiles();
    this->availableParkingSpotsCount = this->parkingSpotsCount;
}

bool CarPark::isEmptyParkingSpot(Coordinates coordinates) {
    return this->carParkContainer.isEmptySpot(coordinates);
}

bool CarPark::isOccupiedParkingSpot(Coordinates coordinates) {
    return this->carParkContainer.isOccupiedSpot(coordinates);
}
