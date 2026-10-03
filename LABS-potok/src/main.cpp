#include <iostream>
#include <fstream>

#include "export.h"

int main() {
    const int BOOKINGS_COUNT = 1000000;

    // Запись в выходной файл
    std::ofstream file("output.txt");
    file << BOOKINGS_COUNT;
    writer(file, BOOKINGS_COUNT);
}