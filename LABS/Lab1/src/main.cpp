#include <iostream>
#include <fstream>

#include "export.h"

int main() {
    const int BOOKINGS_COUNT = 1000;
    const std::string output = "output_" + std::to_string(BOOKINGS_COUNT) + ".txt";
    // Запись в выходной файл
    std::ofstream file(output);
    file << BOOKINGS_COUNT << "\n";
    writer(file, BOOKINGS_COUNT);
}