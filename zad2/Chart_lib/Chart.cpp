//
// Created by rasztabigab on 18.03.2021.
//

#include "Chart.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

std::ostream &operator<<(std::ostream &out, Chart chart) {
    double average_sale_price = chart.calculate_average_sale_price();
    out << "Średnia cena sprzedanych pojazdów: " << average_sale_price << std::endl;

    for (const Car &car : chart.cars) {
        out << car.abbreviation << " Odchylenie: " << car.calculate_deviation(average_sale_price) << std::endl;
    }

    return out;
}

std::istream &operator>>(std::istream &in, Chart &chart) {
    std::string input;
    getline(in, input);

    std::stringstream ss(input);

    Car car;
    ss >> car.make;
    ss >> car.model;
    ss >> car.price;

    std::string two_chars_of_make = car.make.substr(0, 2);
    std::string two_chars_of_model = car.model.substr(0, 2);

    std::transform(two_chars_of_make.begin(), two_chars_of_make.end(), two_chars_of_make.begin(), ::toupper);
    std::transform(two_chars_of_model.begin(), two_chars_of_model.end(), two_chars_of_model.begin(), ::toupper);

    car.abbreviation = two_chars_of_make + two_chars_of_model;

    std::vector<int> carSales;
    int temp;
    while (ss >> temp) {
        carSales.push_back(temp);
    }

    car.sales = carSales;

    // Check to prevent adding a car with all empty fields due to empty line in file
    if (!car.make.empty()) {
        chart.cars.push_back(car);
    }

    return in;
}

double Chart::calculate_average_sale_price() {
    double sum = 0.0;
    int number_of_cars = 0;
    for (const Car &car : cars) {
        int num_of_bought_cars = 0;
        for (int bought_cars : car.sales) {
            num_of_bought_cars += bought_cars;
        }
        sum += (car.price * num_of_bought_cars);
        number_of_cars += num_of_bought_cars;
    }
    return std::round(sum / number_of_cars);
}

void Chart::draw() {
    int cars_sold_by_month[12];
    for (int i = 0; i < 12; ++i) {
        int sum = 0;
        for (Car car : cars) {
            sum += car.sales[i];
        }
        cars_sold_by_month[i] = sum;
    }

    // TODO INCREASE RESOLUTION TO 1
    // TODO REMOVE MAGIC NUMBERS

    char canvas[20][25]{};

    for (int i = 0; i < 12; ++i) {
        for (int j = 3; j < (cars_sold_by_month[i] / 5) + 3; ++j) {
            canvas[i][j] = '#';
        }
        // add month tag
        // TODO FIX
        canvas[i][0] = (i / 10) + 48;
        canvas[i][1] = (i % 10) + 49;
        canvas[i][2] = ' ';
    }


    std::cout << "One # represents 5 sold cars." << std::endl;

    // TODO Add rotate 90* left

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 25; ++j) {
            std::cout << canvas[i][j];
        }
        std::cout << std::endl;
    }

//    for (int i = 23; i >= 0; --i) {
//        for (int j = 0; j < 24; ++j) {
//            std::cout << canvas[j][i];
//        }
//        std::cout << std::endl;
//    }
}

double Car::calculate_deviation(double base) const {
    return price - base;
}


