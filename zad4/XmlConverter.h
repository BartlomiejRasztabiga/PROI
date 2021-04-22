#pragma once


#include <string>
#include <vector>
#include "XmlNode.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

class XmlConverter {
public:
    static XmlNode *rectangleToXmlNode(Rectangle *rectangle);

    static XmlNode *circleToXmlNode(Circle *circle);

    static XmlNode *lineToXmlNode(Line *line);
};


