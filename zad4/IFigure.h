#pragma once


#include <string>
#include <memory>
#include "RGB.h"
#include "XmlNode.h"

enum FigureType {
    RECTANGLE,
    CIRCLE,
    LINE
};

class IFigure {
public:
    virtual ~IFigure() = default;

    virtual IFigure *clone() const = 0;

    virtual double getArea() = 0;

    virtual double getPerimeter() = 0;

    virtual RGB getColor() = 0;

    virtual XmlNode *toXmlNode() = 0;

    virtual FigureType getType() = 0;

    virtual void validateFigureDimensions(int drawingWidth, int drawingHeight) = 0;
};

