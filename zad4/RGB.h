#pragma once

#include <string>

enum Color {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    PURPLE,
    PINK,
    BROWN,
    GRAY,
    BLACK,
    WHITE
};

class RGB {
public:
    RGB(unsigned char r, unsigned char g, unsigned char b);

    explicit RGB(Color color);

    std::string toString() const;

    friend bool operator==(const RGB &lhs, const RGB &rhs);

private:
    void init(unsigned char _r, unsigned char _g, unsigned char _b);

    unsigned char r;
    unsigned char g;
    unsigned char b;
};