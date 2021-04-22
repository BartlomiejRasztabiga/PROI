#pragma once


#include "IFigure.h"

class Rectangle : public IFigure {
public:
    Rectangle(int x, int y, int width, int height, RGB color = RGB(BLACK));

    IFigure *clone() const override;

    double getArea() override;

    double getPerimeter() override;

    XmlNode *toXmlNode() override;

    FigureType getType() override;

    void validateFigureDimensions(int drawingWidth, int drawingHeight) override;

    int getX() const;

    void setX(int _x);

    int getY() const;

    void setY(int _y);

    int getWidth() const;

    void setWidth(int _width);

    int getHeight() const;

    void setHeight(int _height);

    RGB getColor() override;

    void setColor(const RGB &_color);

private:
    int x;
    int y;
    int width;
    int height;
    RGB color;
};


