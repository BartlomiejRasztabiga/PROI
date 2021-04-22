cmake_minimum_required(VERSION 3.19)
project(zad4)

set(CMAKE_CXX_STANDARD 11)

add_executable(zad4 main.cpp Drawing.cpp Drawing.h IFigure.h RGB.cpp RGB.h Rectangle.cpp Rectangle.h XmlConverter.h XmlNodeAttribute.h XmlNodeAttribute.cpp XmlDocument.cpp XmlDocument.h XmlNode.cpp XmlNode.h Circle.cpp Circle.h Line.cpp Line.h XmlConverter.cpp exceptions.h DrawingSnapshot.cpp DrawingSnapshot.h)

add_executable(zad4_tests DrawingTests.cpp doctest.h Drawing.cpp Drawing.h IFigure.h RGB.cpp RGB.h Rectangle.cpp Rectangle.h XmlConverter.h XmlNodeAttribute.h XmlNodeAttribute.cpp XmlDocument.cpp XmlDocument.h XmlNode.cpp XmlNode.h Circle.cpp Circle.h Line.cpp Line.h XmlConverter.cpp exceptions.h DrawingSnapshot.cpp DrawingSnapshot.h)