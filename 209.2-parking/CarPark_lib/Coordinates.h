# pragma once

struct Coordinates {
    int x;
    int y;

    bool operator==(const Coordinates &rhs) const {
        return this->x == rhs.x && this->y == rhs.y;
    }
};


