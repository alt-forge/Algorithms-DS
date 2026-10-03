#include <iostream>
#include <fstream>
#include <array>

#include "passport_gen.h"
#include "date_gen.h"
#include "rooms_nums_gen.h"
#include "price_gen.h"
#include "data_types.h"
#include "conf.h"
#include "export.h"


int main() {
    std::array<booking, BOOKINGS_COUNT> bookings;
    std::ofstream file("output.txt");
    
    // Генерация
    generate_passports(bookings);
    generate_date(bookings);
    generate_rooms_nums(bookings);
    generate_price(bookings);

    // Запись в выходной файл
    writer(bookings, file);
}