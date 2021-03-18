//
// Created by rasztabigab on 11.03.2021.
//

#ifndef LAB1_CAR_H
#define LAB1_CAR_H

#include "string"


class Car {
public:
    std::string brand;
    std::string model;
    int year;
    Car(std::string brand,  std::string model, int year);

    void info();
};


#endif //LAB1_CAR_H
