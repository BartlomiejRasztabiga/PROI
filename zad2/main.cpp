//
// Created by rasztabigab on 18.03.2021.
//

#include <iostream>
#include <fstream>
#include "CarChart.h"


int main(int argc, char *argv[]) {
    // validate if an argument was passed
    if (argc == 1) {
        std::cout << "You have to pass a filename." << std::endl;
        exit(-1);
    }

    // open file input stream
    std::string filename = argv[1];
    std::ifstream fileInputStream(filename);

    // if error has occurred during reading, exit program
    if (!fileInputStream.is_open()) {
        std::cout << "Cannot read the file." << std::endl;
        exit(-1);
    }

    // read input data for the chart
    CarChart chart;
    while (fileInputStream.good()) {
        fileInputStream >> chart;
    }

    chart.draw();

    // write chart output to file
    std::ofstream fileOutputStream("o_" + filename);
    fileOutputStream << chart;

    return 0;
}
