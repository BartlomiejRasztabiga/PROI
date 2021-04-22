#include "XmlNodeAttribute.h"

std::string XmlNodeAttribute::toString() const {
    return " " + this->key + "=\"" + this->value + "\"";
}

XmlNodeAttribute::XmlNodeAttribute(std::string key, std::string value) : key(std::move(key)), value(std::move(value)) {}

XmlNodeAttribute::XmlNodeAttribute(std::string key, int value) : key(std::move(key)), value(std::to_string(value)) {}
