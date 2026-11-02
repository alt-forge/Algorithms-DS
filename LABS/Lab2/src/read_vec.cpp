#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "read_vec.h"

#include "calcDate.h"
#include "searches.h"
#include "data_types.h"

std::vector<booking> read_in_vector(std::string& filename) {
    std::ifstream fin(filename);
    std::size_t n;
    fin >> n;
    fin.ignore();

    std::vector<booking> vec;

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

        int dummy = 0;
        int k = linearSearch_vec(vec, days, dummy);
        vec.insert(vec.begin() + k, b);

    }

    return vec;
}