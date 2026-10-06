#include <iostream>
#include <string>
#include "read_arr.h"
#include "read_vector.h"
#include "read_arr_sort.h"

int main() {
    std::string filename = "output_1000.txt";

    booking* arr = read_in_arr(filename);
    booking* arr_sort = read_in_arr_sort(filename);
    std::vector<booking> vec = read_in_vector(filename);
    
    for (int i = 0; i < 1000; i++) {
        std::cout << arr[i].passport << "\n";
    }
    return 0;
}