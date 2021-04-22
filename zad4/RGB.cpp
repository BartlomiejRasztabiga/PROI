#include "RGB.h"

RGB::RGB(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}

RGB::RGB(Color color) {
    switch (color) {
        case RED:
            init(255, 0, 0);
            break;
        case ORANGE:
            init(255, 128, 0);
            break;
        case YELLOW:
            init(255, 255, 0);
            break;
        case GREEN:
            init(0, 255, 0);
            break;
        case BLUE:
            init(0, 0, 255);
            break;
        case PURPLE:
            init(127, 0, 255);
            break;
        case PINK:
            init(255, 0, 255);
            break;
        case BROWN:
            init(102, 51, 0);
            break;
        case GRAY:
            init(128, 128, 128);
            break;
        case BLACK:
            init(0, 0, 0);
            break;
        case WHITE:
            init(255, 255, 255);
            break;
    }
}

void RGB::init(unsigned char _r, unsigned char _g, unsigned char _b) {
    this->r = _r;
    this->g = _g;
    this->b = _b;
}

std::string RGB::toString() const {
    return "rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
}

bool operator==(const RGB &lhs, const RGB &rhs) {
    return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
}
