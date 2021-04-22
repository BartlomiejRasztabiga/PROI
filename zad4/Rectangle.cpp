#include "Rectangle.h"
#include "XmlConverter.h"
#include "exceptions.h"

Rectangle::Rectangle(int x, int y, int width, int height, RGB color) : x(x), y(y), width(width), height(height),
                                                                       color(color) {}

double Rectangle::getArea() {
    return this->width * this->height;
}

double Rectangle::getPerimeter() {
    return 2 * this->width + 2 * this->height;
}

RGB Rectangle::getColor() {
    return this->color;
}

XmlNode *Rectangle::toXmlNode() {
    return XmlConverter::rectangleToXmlNode(this);
}

FigureType Rectangle::getType() {
    return RECTANGLE;
}

void Rectangle::validateFigureDimensions(int drawingWidth, int drawingHeight) {
    if ((x < 0 || x > drawingWidth) || (y < 0 || y > drawingHeight)) {
        throw FigureOutOfBoundsException();
    }
}

IFigure *Rectangle::clone() const {
    return new Rectangle(this->x, this->y, this->width, this->height, this->color);
}

int Rectangle::getX() const {
    return x;
}

void Rectangle::setX(int _x) {
    Rectangle::x = _x;
}

int Rectangle::getY() const {
    return y;
}

void Rectangle::setY(int _y) {
    Rectangle::y = _y;
}

int Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(int _width) {
    Rectangle::width = _width;
}

int Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(int _height) {
    Rectangle::height = _height;
}

void Rectangle::setColor(const RGB &_color) {
    Rectangle::color = _color;
}
