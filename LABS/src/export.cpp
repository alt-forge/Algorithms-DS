#include <fstream>
#include <array>

#include "export.h"
#include "data_types.h"
#include "conf.h"

void writer(std::array<booking, BOOKINGS_COUNT> bookings, std::ofstream& file) {
    // Вывод в итоговый файл
    for (int i = 0; i < BOOKINGS_COUNT; i++) {
        file << bookings[i].passport;
        file << " ";
        file << bookings[i].date_booking;
        file << " ";

        bool first = true;
        for (int room : bookings[i].rooms_nums) {
            if (!first) file << ',';
            file << room;
            first = false;
        }
        
        file << " ";
        file << bookings[i].price;
        file << "\n";
    }
}
