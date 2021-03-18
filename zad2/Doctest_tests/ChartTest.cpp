// provides main(); this line is required in only one .cpp file
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Chart.h"


TEST_CASE("testing the Chart class") {
    Chart chart;
    std::cout << chart;

    CHECK(true == true);
}
