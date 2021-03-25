#include <iostream>
#include "Car.h"

class ClassWithPtr {
public:
    int *ReturnPtr() {
        int *int_array = new int[9];
        return int_array;
    }
};


int main() {
    ClassWithPtr ptr;
//    int *ptr_arr = ptr.ReturnPtr();

    int *int_array = new int[9];

    return 0;
}
