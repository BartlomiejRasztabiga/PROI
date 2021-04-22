#pragma once


#include "Drawing.h"
#include "XmlNode.h"

class XmlDocument {
public:
    XmlDocument();

    ~XmlDocument();

    void setRoot(XmlNode *newRoot);

    std::string toString() const;

    static XmlDocument *fromDrawing(const Drawing &drawing);

    static XmlDocument *fromDrawingSnapshot(const Drawing &drawing, const DrawingSnapshot &drawingSnapshot);

    friend std::ostream &operator<<(std::ostream &out, const XmlDocument &xmlDocument);

private:
    XmlNode *root = nullptr;
};


