// provides main(); this line is required in only one .cpp file
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "CarChart.h"


TEST_CASE("Given car with empty fields When calling Car::is_valid Then will return false") {
    Car car;

    CHECK(car.is_valid() == false);
}

TEST_CASE("Given car with all fields When calling Car::is_valid Then will return true") {
    Car car;
    car.make = "Test";
    car.model = "Model";
    car.price = 0;
    car.sales = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    CHECK(car.is_valid() == true);
}

TEST_CASE("Given stream with 12 int values When calling read_car_sales_from_stream Then will return them") {
    // given
    std::string values_str = "1 2 3 4 5 6 7 8 9 10 11 12";
    std::stringstream values_stream(values_str);

    // when
    std::vector<int> sales = Car::read_car_sales_from_stream(values_stream);

    // then
    CHECK(std::equal(sales.begin(), sales.end(), std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}.begin()));
}

TEST_CASE("Given car When calling get_abbreviation Then will return one") {
    Car car;
    car.make = "Test";
    car.model = "Model";

    CHECK(car.get_abbreviation() == "TEMO");
}

TEST_CASE("Given stream with required data When calling read_car_from_stream Then will read one") {
    // given
    std::string values_str = "Toyota\tAygo\t34900\t4\t5\t6\t7\t8\t9\t12\t2\t3\t6\t8\t9";
    std::stringstream values_stream(values_str);

    // when
    Car car = Car::read_car_from_stream(values_stream);

    // then
    CHECK(car.is_valid() == true);
    CHECK(car.make == "Toyota");
    CHECK(car.model == "Aygo");
    CHECK(car.price == 34900);
    CHECK(std::equal(car.sales.begin(), car.sales.end(),
                     std::vector<int>{4, 5, 6, 7, 8, 9, 12, 2, 3, 6, 8, 9}.begin()));
}

TEST_CASE("Given car with lower price than average When calling calculate_deviation Then will return negative one") {
    Car car;
    car.make = "Test";
    car.model = "Model";
    car.price = 10000;

    CHECK(car.calculate_deviation(15000) == -5000);
}

TEST_CASE("Given car with higher price than average When calling calculate_deviation Then will return positive one") {
    Car car;
    car.make = "Test";
    car.model = "Model";
    car.price = 15000;

    CHECK(car.calculate_deviation(10000) == 5000);
}

TEST_CASE("Given january When calling get_month_label Then will return 1") {
    CHECK(CarChart::get_month_label(0) == "1");
}

TEST_CASE("Given october When calling get_month_label Then will return 10") {
    CHECK(CarChart::get_month_label(9) == "10");
}

TEST_CASE(
        "Given chart with multiple cars When calling get_cars_sold_by_month Then will set array of cars sold per month") {
    // given
    CarChart chart;

    std::string values_str = "Toyota\tAygo\t34900\t4\t5\t6\t7\t8\t9\t12\t2\t3\t6\t8\t9";
    std::stringstream values_stream1(values_str);
    values_stream1 >> chart;

    values_str = "Opel\tAdam\t43300\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12";
    std::stringstream values_stream2(values_str);
    values_stream2 >> chart;

    // when
    int cars_sold_by_month[12];
    chart.get_cars_sold_by_month(cars_sold_by_month);

    // then
    CHECK(cars_sold_by_month[0] == 5);
    CHECK(cars_sold_by_month[1] == 7);
}

TEST_CASE(
        "Given chart with multiple cars When calling calculate_average_sale_price Then will return average car price") {
    // given
    CarChart chart;

    std::string values_str = "Toyota\tAygo\t34900\t4\t5\t6\t7\t8\t9\t12\t2\t3\t6\t8\t9";
    std::stringstream values_stream1(values_str);
    values_stream1 >> chart;

    values_str = "Opel\tAdam\t43300\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12";
    std::stringstream values_stream2(values_str);
    values_stream2 >> chart;

    // when
    double avg = chart.calculate_average_sale_price();

    // then
    CHECK(avg == 39073.0);
}

TEST_CASE(
        "Given chart with multiple cars When calling output to stream operator Then will return appropriate data") {
    // given
    CarChart chart;

    std::string values_str = "Toyota\tAygo\t34900\t4\t5\t6\t7\t8\t9\t12\t2\t3\t6\t8\t9";
    std::stringstream values_stream1(values_str);
    values_stream1 >> chart;

    values_str = "Opel\tAdam\t43300\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12";
    std::stringstream values_stream2(values_str);
    values_stream2 >> chart;

    // when
    std::stringstream output;
    output << chart;

    // then
    std::string line;
    std::getline(output, line);
    CHECK(line == "Średnia cena sprzedanych pojazdów: 39073");
    std::getline(output, line);
    CHECK(line == "TOAY Odchylenie: -4173");
    std::getline(output, line);
    CHECK(line == "OPAD Odchylenie: 4227");
    std::getline(output, line);
    CHECK(line.empty() == true);
}

TEST_CASE(
        "Given chart with multiple cars When calling draw Then will draw bar chart of sold cars by month") {
    // given
    CarChart chart;

    std::string values_str = "Toyota\tAygo\t34900\t4\t5\t6\t7\t8\t9\t12\t2\t3\t6\t8\t9";
    std::stringstream values_stream1(values_str);
    values_stream1 >> chart;

    values_str = "Opel\tAdam\t43300\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12";
    std::stringstream values_stream2(values_str);
    values_stream2 >> chart;

    // when
    std::stringstream output;
    chart.draw(output);

    // then
    std::string line;
    std::getline(output, line);
    CHECK(line == "One # represents 1 sold car.");
    std::getline(output, line);
    CHECK(line == "1  #####");
    std::getline(output, line);
    CHECK(line == "2  #######");
    std::getline(output, line);
    CHECK(line == "3  #########");
    std::getline(output, line);
    CHECK(line == "4  ###########");
    std::getline(output, line);
    CHECK(line == "5  #############");
    std::getline(output, line);
    CHECK(line == "6  ###############");
    std::getline(output, line);
    CHECK(line == "7  ###################");
    std::getline(output, line);
    CHECK(line == "8  ##########");
    std::getline(output, line);
    CHECK(line == "9  ############");
    std::getline(output, line);
    CHECK(line == "10 ################");
    std::getline(output, line);
    CHECK(line == "11 ###################");
    std::getline(output, line);
    CHECK(line == "12 #####################");
    std::getline(output, line);
    CHECK(line.empty() == true);
}