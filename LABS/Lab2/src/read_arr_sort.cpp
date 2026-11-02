#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "calcDate.h"
#include "searchs.h"
#include "data_types.h"
#include "read_arr_sort.h"
#include <utility>

std::pair<booking*, int> read_in_arr_sort(std::string& filename) {
    std::ifstream fin(filename);
    std::size_t n;
    fin >> n;
    fin.ignore();

    int filled = 0;
    booking* arr = new booking[n];

    std::string line;
    for (std::size_t i = 0; i < n && std::getline(fin, line); i++) {
        std::istringstream iss(line);

        booking b{};
        iss >> b.passport;

        char dot1, dot2;
        iss >> b.date_booking.day >> dot1
            >> b.date_booking.month >> dot2
            >> b.date_booking.year;

        iss >> b.price;

        char ch;
        if (iss >> ch && ch == '{') {
            int value;
            while (iss >> value) {
                b.rooms_nums.insert(value);
                if (!(iss >> ch) || ch == '}') break;
            }
        }

        int days = calcDate(b.date_booking);

        int k = linearSearch_arr(arr, days, filled);

        for (int j = filled; j > k; --j)
            arr[j] = arr[j - 1];

        arr[k] = b;
        ++filled;
    }

    return {arr, n};
}