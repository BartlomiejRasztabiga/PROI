#pragma once

#include "IFigure.h"


class Line : public IFigure {
public:
    Line(int x1, int y1, int x2, int y2, int width, RGB color = RGB(BLACK));

    IFigure *clone() const override;

    double getArea() override;

    double getPerimeter() override;

    RGB getColor() override;

    XmlNode *toXmlNode() override;

    FigureType getType() override;

    void validateFigureDimensions(int drawingWidth, int drawingHeight) override;

    int getX1() const;

    void setX1(int _x1);

    int getY1() const;

    void setY1(int _y1);

    int getX2() const;

    void setX2(int _x2);

    int getY2() const;

    void setY2(int _y2);

    int getWidth() const;

    void setWidth(int _width);

    void setColor(const RGB &_color);

private:
    int x1;
    int y1;
    int x2;
    int y2;
    int width;
    RGB color;
};

