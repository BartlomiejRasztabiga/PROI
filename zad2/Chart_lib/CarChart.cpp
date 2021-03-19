//
// Created by rasztabigab on 18.03.2021.
//

#include "CarChart.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>

std::ostream &operator<<(std::ostream &out, const CarChart &chart) {
    double average_sale_price = chart.calculate_average_sale_price();
    out << "Średnia cena sprzedanych pojazdów: " << average_sale_price << std::endl;

    for (const Car &car : chart.cars) {
        out << car.abbreviation << " Odchylenie: " << car.calculate_deviation(average_sale_price) << std::endl;
    }

    return out;
}

std::istream &operator>>(std::istream &in, CarChart &chart) {
    std::string input;
    getline(in, input);

    std::stringstream ss(input);

    Car car = Car::read_car_from_stream(ss);

    // Check to prevent adding invalid car due to empty line in file
    if (car.is_valid()) {
        chart.cars.push_back(car);
    }

    return in;
}

double CarChart::calculate_average_sale_price() const {
    double sum = 0.0;
    int number_of_cars = 0;

    for (const Car &car : cars) {
        int num_of_bought_cars = std::accumulate(car.sales.begin(), car.sales.end(), 0);
        sum += (car.price * num_of_bought_cars);
        number_of_cars += num_of_bought_cars;
    }

    return std::round(sum / number_of_cars);
}

void CarChart::draw(std::ostream &out) {
    const int x = 12;
    const int y = 100;

    int cars_sold_by_month[12];
    get_cars_sold_by_month(cars_sold_by_month);

    char canvas[x][y]{};

    int left_margin_size = 3;

    for (int i = 0; i < x; ++i) {
        for (int j = left_margin_size; j < (cars_sold_by_month[i]) + left_margin_size; ++j) {
            canvas[i][j] = '#';
        }

        std::string month_label = get_month_label(i);
        canvas[i][0] = month_label[0];
        canvas[i][1] = month_label[1];
        canvas[i][2] = ' ';
    }

    out << "One # represents 1 sold car." << std::endl;

    for (auto &row : canvas) {
        out << row << std::endl;
    }
}

void CarChart::get_cars_sold_by_month(int *cars_sold_by_month) {
    for (int i = 0; i < 12; ++i) {
        int sum = 0;
        for (Car car : cars) {
            sum += car.sales[i];
        }
        cars_sold_by_month[i] = sum;
    }
}

std::string CarChart::get_month_label(int month_index) {
    std::string month_label = std::to_string(month_index + 1);
    if (month_label[1] == '\0') {
        month_label[1] = ' ';
    }
    return month_label;
}

double Car::calculate_deviation(double base) const {
    return price - base;
}

Car Car::read_car_from_stream(std::stringstream &ss) {
    Car car;
    ss >> car.make;
    ss >> car.model;
    ss >> car.price;

    car.abbreviation = car.get_abbreviation();
    car.sales = Car::read_car_sales_from_stream(ss);

    return car;
}

std::string Car::get_abbreviation() const {
    std::string two_chars_of_make = make.substr(0, 2);
    std::string two_chars_of_model = model.substr(0, 2);

    std::transform(two_chars_of_make.begin(), two_chars_of_make.end(), two_chars_of_make.begin(), ::toupper);
    std::transform(two_chars_of_model.begin(), two_chars_of_model.end(), two_chars_of_model.begin(), ::toupper);

    return two_chars_of_make + two_chars_of_model;
}

std::vector<int> Car::read_car_sales_from_stream(std::stringstream &ss) {
    std::vector<int> carSales;
    int temp;
    while (ss >> temp) {
        carSales.push_back(temp);
    }
    assert(carSales.size() == 12);
    return carSales;
}

bool Car::is_valid() const {
    return !make.empty() && !model.empty() && !sales.empty();
}


