#pragma once

#include "IFigure.h"
#include "RGB.h"

class Circle : public IFigure {
public:
    Circle(int x, int y, int radius, RGB color = RGB(BLACK));

    IFigure *clone() const override;

    double getArea() override;

    double getPerimeter() override;

    RGB getColor() override;

    XmlNode *toXmlNode() override;

    FigureType getType() override;

    void validateFigureDimensions(int drawingWidth, int drawingHeight) override;

    int getX() const;

    int getY() const;

    int getRadius() const;

    void setX(int _x);

    void setY(int _y);

    void setRadius(int _radius);

    void setColor(const RGB &_color);

private:
    int x;
    int y;
    int radius;
    RGB color;
};

