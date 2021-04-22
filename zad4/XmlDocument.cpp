#include "XmlDocument.h"

XmlDocument::XmlDocument() = default;

XmlDocument::~XmlDocument() {
    delete this->root;
}

void XmlDocument::setRoot(XmlNode *newRoot) {
    this->root = newRoot;
}

XmlDocument *XmlDocument::fromDrawing(const Drawing &drawing) {
    return XmlDocument::fromDrawingSnapshot(drawing, *drawing.getLatestSnapshot());
}

XmlDocument *XmlDocument::fromDrawingSnapshot(const Drawing &drawing, const DrawingSnapshot &drawingSnapshot) {
    auto *xml = new XmlDocument();

    auto *html = new XmlNode("html");

    auto *body = new XmlNode("body");

    auto *svg = new XmlNode("svg");
    svg->addAttribute(XmlNodeAttribute("width", drawing.getWidth()));
    svg->addAttribute(XmlNodeAttribute("height", drawing.getHeight()));

    xml->setRoot(html);
    html->addNode(body);
    body->addNode(svg);

    for (IFigure *figure : drawingSnapshot) {
        svg->addNode(figure->toXmlNode());
    }

    return xml;
}

std::string XmlDocument::toString() const {
    return "<!DOCTYPE html>\n" + this->root->toString() + "\n";
}

std::ostream &operator<<(std::ostream &out, const XmlDocument &xmlDocument) {
    out << xmlDocument.toString();

    return out;
}
