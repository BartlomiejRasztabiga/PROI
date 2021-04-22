#include "XmlNode.h"

#include <utility>

XmlNode::XmlNode(std::string tag) : tag(std::move(tag)) {}

XmlNode::~XmlNode() {
    for (XmlNode *node : this->nodes) {
        delete node;
    }
    this->nodes.clear();
}

void XmlNode::addAttribute(const XmlNodeAttribute &attribute) {
    this->attributes.push_back(attribute);
}

void XmlNode::addNode(XmlNode *node) {
    this->nodes.push_back(node);
}

std::string XmlNode::toString() {
    // add opening tag
    std::string result = "<" + this->tag;

    // add tag attributes
    if (!this->attributes.empty()) {
        for (const XmlNodeAttribute &attribute : this->attributes) {
            result += attribute.toString();
        }
    }

    // if no children, close tag. Otherwise start new line
    if (this->nodes.empty()) {
        result += " />";
        return result;
    } else {
        result += ">\n";
    }

    // add node's children
    for (XmlNode *node : this->nodes) {
        result += node->toString();
        result += "\n";
    }

    // add closing tag
    result += "</" + this->tag + ">";

    return result;
}
