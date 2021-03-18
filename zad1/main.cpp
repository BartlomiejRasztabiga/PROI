#include <iostream>
#include "Car.h"

void checkFloatPrecision() {
    const double epsilon = 0.01;

    float i = 0;
    double j = 0;
    while (std::abs(i - j) <= epsilon) {
        i += 1.0f;
        j += 1.0;
    }
    std::cout << "Max float value while keeping precision: " << std::fixed << i << std::endl;
}

void forceError() {
    // "Array out of bounds" error
    int foo[1];
    for (int i = 0; i <= 1; i++) {
        foo[i] = i;
    }
}

int main() {
    auto car = Car("Peugeot", "508", 2013);
    car.info();

    checkFloatPrecision();

//    forceError();

    return 0;
}
