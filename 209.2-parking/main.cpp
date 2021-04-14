#include <iostream>
#include <fstream>
#include "CarPark.h"


int main(int argc, char *argv[]) {
    CarPark carPark;
    if (argc == 2) {
        std::string filename = argv[1];
        // open file input stream
        std::ifstream fileInputStream(filename);

        // if error has occurred during reading, exit program
        if (!fileInputStream.is_open()) {
            std::cout << "Cannot read the file." << std::endl;
            exit(-1);
        }

        // deserialize car park from file
        fileInputStream >> carPark;

        // close input stream
        fileInputStream.close();

        // open file output stream
        std::ofstream fileOutputStream(filename);

        // some operations on CarPark, will be done through GUI afterwards
        try {
            carPark.parkCar();
            carPark.parkCar();
            carPark.parkCar();
        } catch (std::exception &e) {
            std::cerr << e.what();
        }

        // serialize car park to file
        fileOutputStream << carPark;

        // close input stream
        fileOutputStream.close();
    }

    return 0;
}
