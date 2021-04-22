#include "Line.h"
#include "XmlConverter.h"
#include "exceptions.h"

Line::Line(int x1, int y1, int x2, int y2, int width, RGB color) : x1(x1), y1(y1), x2(x2), y2(y2),
                                                                   width(width),
                                                                   color(color) {}

double Line::getArea() {
    return 0;
}

double Line::getPerimeter() {
    return 0;
}

XmlNode *Line::toXmlNode() {
    return XmlConverter::lineToXmlNode(this);
}

FigureType Line::getType() {
    return LINE;
}

void Line::validateFigureDimensions(int drawingWidth, int drawingHeight) {
    if ((x1 < 0 || x1 > drawingWidth) || (x2 < 0 || x2 > drawingWidth)
        || (y1 < 0 || y1 > drawingHeight) || (y2 < 0 || y2 > drawingHeight)) {
        throw FigureOutOfBoundsException();
    }
}

IFigure *Line::clone() const {
    return new Line(this->x1, this->y1, this->x2, this->y2, this->width, this->color);
}

RGB Line::getColor() {
    return this->color;
}

int Line::getX1() const {
    return x1;
}

void Line::setX1(int _x1) {
    Line::x1 = _x1;
}

int Line::getY1() const {
    return y1;
}

void Line::setY1(int _y1) {
    Line::y1 = _y1;
}

int Line::getX2() const {
    return x2;
}

void Line::setX2(int _x2) {
    Line::x2 = _x2;
}

int Line::getY2() const {
    return y2;
}

void Line::setY2(int _y2) {
    Line::y2 = _y2;
}

int Line::getWidth() const {
    return width;
}

void Line::setWidth(int _width) {
    Line::width = _width;
}

void Line::setColor(const RGB &_color) {
    Line::color = _color;
}
