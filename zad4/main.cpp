#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include "Drawing.h"
#include "XmlDocument.h"
#include "Circle.h"
#include "Line.h"

int main() {
    IFigure *rectangle = new Rectangle(300, 100, 300, 100);
    IFigure *rectangle2 = new Rectangle(30, 10, 300, 100, RGB(RED));
    IFigure *circle = new Circle(250, 250, 50, RGB(BLUE));
    IFigure *line = new Line(0, 0, 200, 200, 5, RGB(GREEN));

    // initial figures
    Drawing drawing(500, 500);
    drawing.addFigure(*rectangle);
    drawing.addFigure(*rectangle2);
    drawing.addFigure(*circle);
    drawing.addFigure(*line);

    XmlDocument *xml = XmlDocument::fromDrawing(drawing);
    std::cout << (*xml) << std::endl;
    delete xml;

    // update one figure
    drawing.updateFigure(2, Circle(250, 250, 100, RGB(PURPLE)));
    xml = XmlDocument::fromDrawing(drawing);
    std::cout << (*xml) << std::endl;
    delete xml;

    // delete one figure
    drawing.deleteFigure(0);
    xml = XmlDocument::fromDrawing(drawing);
    std::cout << (*xml) << std::endl;

    // open file output stream
    std::ofstream fileOutputStream("output.html");

    // serialize drawing to file
    fileOutputStream << *xml;

    // close input stream
    fileOutputStream.close();

    delete xml;
    delete rectangle;
    delete rectangle2;
    delete circle;
    delete line;
    return 0;
}
