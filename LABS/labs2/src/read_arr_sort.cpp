#include <string>
#include <fstream>
#include "data_types.h"
#include "read_arr_sort.h"

booking* read_in_arr_sort(std::string& filename) {
    std::ifstream fin(filename);
    std::size_t n;
    fin >> n;
    fin.ignore();

    booking* arr = new booking[n];

    return arr;
}