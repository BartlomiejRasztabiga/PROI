//
// Created by rasztabigab on 18.03.2021.
//

#ifndef ZAD2_CARCHART_H
#define ZAD2_CARCHART_H


#include <string>
#include <vector>
#include <iostream>

struct Car {
    std::string make;
    std::string model;
    std::string abbreviation;
    int price;
    std::vector<int> sales;

    double calculate_deviation(double base) const;

    std::string get_abbreviation() const;

    bool is_valid() const;

    static std::vector<int> read_car_sales_from_stream(std::stringstream &ss);

    static Car read_car_from_stream(std::stringstream &ss);
};

class CarChart {
public:

    friend std::ostream &operator<<(std::ostream &out, const CarChart &chart);

    friend std::istream &operator>>(std::istream &in, CarChart &chart);

    std::vector<Car> cars;

    double calculate_average_sale_price() const;

    void draw(std::ostream &out = std::cout);

    static std::string get_month_label(int month_index);

    void get_cars_sold_by_month(int *cars_sold_by_month);
};


#endif //ZAD2_CARCHART_H
