#pragma once

#include <string>
#include <utility>

class XmlNodeAttribute {
public:
    XmlNodeAttribute(std::string key, std::string value);

    XmlNodeAttribute(std::string key, int value);

    std::string toString() const;

private:
    std::string key;
    std::string value;
};

