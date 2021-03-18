//
// Created by rasztabigab on 18.03.2021.
//

#include <iostream>
#include <fstream>
#include "Chart_lib/Chart.h"

// TODO ADD TESTS

// TODO REFACTOR

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "You have to pass a filename." << std::endl;
        exit(-1);
    }

    std::string filename = argv[1];

    std::ifstream fileInputStream(filename);

    if (!fileInputStream.is_open()) {
        std::cout << "Cannot read the file." << std::endl;
        exit(-1);
    }

    Chart chart;
    while (fileInputStream.good()) {
        fileInputStream >> chart;
    }

    chart.draw();

    std::ofstream fileOutputStream("o_" + filename);
    fileOutputStream << chart;


    return 0;
}
