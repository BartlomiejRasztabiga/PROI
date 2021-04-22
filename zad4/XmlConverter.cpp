#include "XmlConverter.h"

XmlNode *XmlConverter::rectangleToXmlNode(Rectangle *rectangle) {
    XmlNode *xml = new XmlNode("rect");

    xml->addAttribute(XmlNodeAttribute("x", rectangle->getX()));
    xml->addAttribute(XmlNodeAttribute("y", rectangle->getY()));
    xml->addAttribute(XmlNodeAttribute("width", rectangle->getWidth()));
    xml->addAttribute(XmlNodeAttribute("height", rectangle->getHeight()));
    xml->addAttribute(XmlNodeAttribute("style", "fill:" + rectangle->getColor().toString()));

    return xml;
}

XmlNode *XmlConverter::circleToXmlNode(Circle *circle) {
    XmlNode *xml = new XmlNode("circle");

    xml->addAttribute(XmlNodeAttribute("cx", circle->getX()));
    xml->addAttribute(XmlNodeAttribute("cy", circle->getY()));
    xml->addAttribute(XmlNodeAttribute("r", circle->getRadius()));
    xml->addAttribute(XmlNodeAttribute("style", "fill:" + circle->getColor().toString()));

    return xml;
}

XmlNode *XmlConverter::lineToXmlNode(Line *line) {
    XmlNode *xml = new XmlNode("line");

    xml->addAttribute(XmlNodeAttribute("x1", line->getX1()));
    xml->addAttribute(XmlNodeAttribute("y1", line->getY1()));
    xml->addAttribute(XmlNodeAttribute("x2", line->getX2()));
    xml->addAttribute(XmlNodeAttribute("y2", line->getY2()));
    xml->addAttribute(XmlNodeAttribute("style",
                                       "stroke:" + line->getColor().toString() + ";stroke-width:" +
                                       std::to_string(line->getWidth())));

    return xml;
}
