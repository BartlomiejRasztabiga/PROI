#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "IFigure.h"
#include "Rectangle.h"
#include "RGB.h"
#include "Circle.h"
#include "Line.h"
#include "exceptions.h"
#include "Drawing.h"
#include "XmlDocument.h"

TEST_CASE("Test figures polymorphism") {
    IFigure *rect = new Rectangle(1, 1, 1, 1);
    CHECK(rect->getArea() == 1);
    CHECK(rect->getPerimeter() == 4);
    CHECK(rect->getType() == RECTANGLE);
    CHECK(rect->getColor() == RGB(BLACK));

    IFigure *circle = new Circle(1, 1, 1);
    CHECK(circle->getArea() == M_PI);
    CHECK(circle->getPerimeter() == 2 * M_PI);
    CHECK(circle->getType() == CIRCLE);
    CHECK(circle->getColor() == RGB(BLACK));

    IFigure *line = new Line(1, 1, 2, 2, 1);
    CHECK(line->getArea() == 0);
    CHECK(line->getPerimeter() == 0);
    CHECK(line->getType() == LINE);
    CHECK(line->getColor() == RGB(BLACK));

    delete rect;
    delete circle;
    delete line;
}

TEST_CASE("Test figures validateFigureDimensions") {
    IFigure *rect = new Rectangle(500, 500, 1, 1);
    CHECK_THROWS_AS(rect->validateFigureDimensions(100, 100), FigureOutOfBoundsException);

    IFigure *circ = new Circle(500, 500, 1);
    CHECK_THROWS_AS(circ->validateFigureDimensions(100, 100), FigureOutOfBoundsException);

    IFigure *line = new Line(50, 50, 150, 150, 1);
    CHECK_THROWS_AS(line->validateFigureDimensions(100, 100), FigureOutOfBoundsException);

    delete rect;
    delete circ;
    delete line;
}

TEST_CASE("Test figures toXmlNode") {
    XmlNode *node;
    IFigure *rect = new Rectangle(500, 500, 1, 1);
    node = rect->toXmlNode();
    CHECK(node->toString() ==
          "<rect x=\"500\" y=\"500\" width=\"1\" height=\"1\" style=\"fill:rgb(0,0,0)\" />");
    delete node;

    IFigure *circ = new Circle(500, 500, 1);
    node = circ->toXmlNode();
    CHECK(node->toString() == "<circle cx=\"500\" cy=\"500\" r=\"1\" style=\"fill:rgb(0,0,0)\" />");
    delete node;

    IFigure *line = new Line(50, 50, 150, 150, 1);
    node = line->toXmlNode();
    CHECK(node->toString() ==
          "<line x1=\"50\" y1=\"50\" x2=\"150\" y2=\"150\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />");
    delete node;

    delete rect;
    delete circ;
    delete line;
}

TEST_CASE("Test XmlDocument::fromDrawing") {
    IFigure *rect = new Rectangle(500, 500, 1, 1);
    IFigure *circ = new Circle(500, 500, 1);
    IFigure *line = new Line(50, 50, 150, 150, 1);

    Drawing drawing(500, 500);
    drawing.addFigure(*rect);
    drawing.addFigure(*circ);
    drawing.addFigure(*line);

    XmlDocument *xml = XmlDocument::fromDrawing(drawing);
    CHECK(xml->toString() == "<!DOCTYPE html>\n"
                             "<html>\n"
                             "<body>\n"
                             "<svg width=\"500\" height=\"500\">\n"
                             "<rect x=\"500\" y=\"500\" width=\"1\" height=\"1\" style=\"fill:rgb(0,0,0)\" />\n"
                             "<circle cx=\"500\" cy=\"500\" r=\"1\" style=\"fill:rgb(0,0,0)\" />\n"
                             "<line x1=\"50\" y1=\"50\" x2=\"150\" y2=\"150\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n"
                             "</svg>\n"
                             "</body>\n"
                             "</html>");

    delete rect;
    delete circ;
    delete line;
    delete xml;
}

TEST_CASE("Test Drawing::getSnapshotForTimestamp") {
    IFigure *rect = new Rectangle(500, 500, 1, 1);
    IFigure *rect1 = new Rectangle(50, 50, 10, 10);

    Drawing drawing(500, 500);
    drawing.addFigure(*rect);
    DrawingSnapshot *snapshotAfterRect = drawing.getLatestSnapshot();
    drawing.addFigure(*rect1);
    DrawingSnapshot *snapshotAfterRect1 = drawing.getLatestSnapshot();

    CHECK(drawing.getSnapshotForTimestamp(snapshotAfterRect->getTimestamp()) == snapshotAfterRect);
    CHECK(drawing.getSnapshotForTimestamp(snapshotAfterRect->getTimestamp() + std::chrono::milliseconds(1)) ==
          snapshotAfterRect1);

    delete rect;
    delete rect1;
}

TEST_CASE("Test XmlDocument::fromDrawingSnapshot") {
    IFigure *rect = new Rectangle(500, 500, 1, 1);
    IFigure *rect1 = new Rectangle(50, 50, 10, 10);

    Drawing drawing(500, 500);
    drawing.addFigure(*rect);
    DrawingSnapshot *snapshotAfterRect = drawing.getLatestSnapshot();
    drawing.addFigure(*rect1);

    XmlDocument *xml = XmlDocument::fromDrawingSnapshot(drawing, *snapshotAfterRect);
    CHECK(xml->toString() == "<!DOCTYPE html>\n"
                             "<html>\n"
                             "<body>\n"
                             "<svg width=\"500\" height=\"500\">\n"
                             "<rect x=\"500\" y=\"500\" width=\"1\" height=\"1\" style=\"fill:rgb(0,0,0)\" />\n"
                             "</svg>\n"
                             "</body>\n"
                             "</html>");

    delete rect;
    delete rect1;
    delete xml;
}

TEST_CASE("Test Drawing::updateFigure") {
    IFigure *rect = new Rectangle(500, 500, 1, 1);

    Drawing drawing(500, 500);
    size_t index = drawing.addFigure(*rect);

    IFigure *rectAfterAdd = drawing.getFigure(index);
    CHECK(rectAfterAdd->getArea() == 1);
    delete rectAfterAdd;

    auto *updatedRect = dynamic_cast<Rectangle *>(rect->clone());
    updatedRect->setHeight(10);
    updatedRect->setWidth(10);

    rectAfterAdd = drawing.getFigure(index);
    CHECK(rectAfterAdd->getArea() == 1);
    delete rectAfterAdd;

    drawing.updateFigure(index, *updatedRect);

    rectAfterAdd = drawing.getFigure(index);
    CHECK(rectAfterAdd->getArea() == 100);
    delete rectAfterAdd;

    delete rect;
    delete updatedRect;
}

TEST_CASE("Test Drawing::deleteFigure") {
    IFigure *rect = new Rectangle(500, 500, 1, 1);

    Drawing drawing(500, 500);
    size_t index = drawing.addFigure(*rect);

    IFigure *rectAfterAdd = drawing.getFigure(index);
    CHECK(rectAfterAdd->getArea() == 1);
    delete rectAfterAdd;

    drawing.deleteFigure(index);

    CHECK_THROWS_AS(drawing.getFigure(index), FigureNotFoundException);

    delete rect;
}