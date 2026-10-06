#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "data_types.h"

booking* read_in_arr(std::string& filename) {
    std::ifstream fin(filename);
    std::size_t n;
    fin >> n;
    fin.ignore();

    booking* arr = new booking[n];

    std::string line;
    for (std::size_t i = 0; i < n && std::getline(fin, line); i++) {
        std::istringstream iss(line);

        std::string passport;
        iss >> passport;

        date d{};
        char dot1, dot2;
        iss >> d.day >> dot1 >> d.month >> dot2 >> d.year;

        int price;
        iss >> price;

        std::set<int> rooms_nums;
        char ch;
        if (iss >> ch && ch == '{') {
            int value;
            while (iss >> value) {
                rooms_nums.insert(value);
                if (!(iss >> ch) || ch == '}') break;
            }
        }

        arr[i].passport = passport;
        arr[i].date_booking = d;
        arr[i].price = price;
        arr[i].rooms_nums = rooms_nums;
    }
    
    return arr;
}
