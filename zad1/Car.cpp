//
// Created by rasztabigab on 11.03.2021.
//

#include "Car.h"
#include <iostream>


Car::Car(std::string brand, std::string model, int year) {
    this->brand = brand;
    this->model = model;
    this->year = year;
}

void Car::info() {
#if DEBUG
    std::cout << "DEBUG MODE" << std::endl;
#endif
    std::cout << "Car: " << this->brand << " " << this->model << " (" << this->year << ")" << std::endl;
}
