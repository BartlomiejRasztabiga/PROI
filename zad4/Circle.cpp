#include "Circle.h"
#include "XmlConverter.h"
#include "exceptions.h"
#include <cmath>

Circle::Circle(int x, int y, int radius, RGB color) : x(x), y(y), radius(radius), color(color) {}

double Circle::getArea() {
    return M_PI * std::pow(this->radius, 2);
}

double Circle::getPerimeter() {
    return 2 * M_PI * this->radius;
}

RGB Circle::getColor() {
    return this->color;
}

XmlNode *Circle::toXmlNode() {
    return XmlConverter::circleToXmlNode(this);
}

FigureType Circle::getType() {
    return CIRCLE;
}

void Circle::validateFigureDimensions(int drawingWidth, int drawingHeight) {
    if ((x < 0 || x > drawingWidth) || (y < 0 || y > drawingHeight)) {
        throw FigureOutOfBoundsException();
    }
}

IFigure *Circle::clone() const {
    return new Circle(this->x, this->y, this->radius, this->color);
}

void Circle::setX(int _x) {
    Circle::x = _x;
}

void Circle::setY(int _y) {
    Circle::y = _y;
}

void Circle::setRadius(int _radius) {
    Circle::radius = _radius;
}

void Circle::setColor(const RGB &_color) {
    Circle::color = _color;
}

int Circle::getX() const {
    return this->x;
}

int Circle::getY() const {
    return this->y;
}

int Circle::getRadius() const {
    return this->radius;
}
