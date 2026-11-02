#include <iostream>
#include <string>
#include "workWithTime.h"

void print_time(std::string title, double t1, double t2, double t3) {
    std::cout << title << '\n';
    std::cout << "arr:    " << t1  << " ms\n";
    std::cout << "sort:   " << t2 << " ms\n";
    std::cout << "vector: " << t3  << " ms\n";
    std::cout << '\n';
}
