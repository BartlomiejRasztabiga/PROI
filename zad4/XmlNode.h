#pragma once

#include <memory>
#include <vector>
#include <string>
#include "XmlNodeAttribute.h"

class XmlNode {
public:
    explicit XmlNode(std::string tag);

    ~XmlNode();

    void addAttribute(const XmlNodeAttribute &attribute);

    void addNode(XmlNode *node);

    std::string toString();

private:
    std::string tag;
    std::vector<XmlNodeAttribute> attributes;
    std::vector<XmlNode *> nodes;
};


