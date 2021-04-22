# Zadanie 4

# Bartłomiej Rasztabiga 304117

## Przykładowe użycie:

```c++
#include <iostream>
#include <fstream>
#include "Rectangle.h"
#include "Drawing.h"
#include "XmlDocument.h"
#include "Circle.h"
#include "Line.h"

int main() {
    Rectangle rectangle(300, 100, 300, 100);
    Rectangle rectangle2(30, 10, 300, 100, RGB(RED));
    Circle circle(250, 250, 50, RGB(BLUE));
    Line line(0, 0, 200, 200, 5, RGB(GREEN));
    
    // initial figures
    Drawing drawing(500, 500);
    drawing.addFigure(rectangle);
    drawing.addFigure(rectangle2);
    drawing.addFigure(circle);
    drawing.addFigure(line);
    
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
    return 0;
}

```

## Drawing

Klasa reprezentująca obszar rysunku, przechowujący figury (implementujące interfejs IFigure).

Wspiera ona mechanizm przechowywania historii rysunku. Przy każdej operacji (dodanie/zamiana/usunięcie figury), jest
tworzony nowy snapshot zawierający kopię figur w danym momencie.

Z klasy Drawing (z jej ostatniego lub dowolnego snapshotu) można utworzyć dokument XML będący jej reprezentacją.

Oferuje ona również (wystawiony z klasy DrawingSnapshot) iterator do przeglądania kolekcji figur.

## DrawingSnapshot

Klasa przechowująca wskaźniki na obiekty pochodne IFigure oraz znacznik czasu powstania. Oferuje ona również iterator po
obiektach figur.

Nie należy modyfikować obiektów klasy DrawingSnapshot bezpośrednio, a jedynie przez fasadę klasy Drawing.

## IFigure

Interfejs implementowany przez klasy pochodne figur (Rectangle, Circle, Line).

Zawiera podstawowe metody wirtualny (clone, getArea, getPerimeter, getColor, getType etc.)

## Line, Rectangle, Circle

Klasy implementujące IFigure. Reprezentują kolejno odcinek, prostokąt i koło.

## RGB

Klasa reprezentująca kolor w przestrzeni RGB.

Umożliwia wykorzystanie predefiniowanych kolorów z enumeracji Color oraz eksport do postaci XML.

## XmlConverter

Klasa umożliwiająca konwersję obiektów Line, Rectangle i Circle do odpowiednich obiektów XmlNode.

## XmlDocument

Klasa reprezentująca dokument XML. Umożliwia ona stworzenie dokumentu XML z obiektu Drawing lub DrawingSnapshot. Pozwala
na konwersję dokumentu XML do postaci std::string.

## XmlNode

Klasa reprezentująca węzeł dokumentu XML z atrybutami. Umożliwia ona zagnieżdżanie węzłów oraz konwersję do postaci
std::string.

## XmlNodeAttribute

Klasa reprezentująca atrybut węzła XML, np. "width" dla <svg/>
