//
// Created by rasztabigab on 18.03.2021.
//

#ifndef ZAD2_CHART_H
#define ZAD2_CHART_H


#include <string>
#include <vector>

struct Car {
    std::string make;
    std::string model;
    std::string abbreviation;
    int price;
    std::vector<int> sales;

    double calculate_deviation(double base) const;
    int calculate_num_of_sold_cars() const;
};

class Chart {
public:

    friend std::ostream &operator<<(std::ostream &out, Chart chart);

    friend std::istream &operator>>(std::istream &in, Chart &chart);

    std::vector<Car> cars;

    double calculate_average_sale_price();
    void draw();
};


#endif //ZAD2_CHART_H
