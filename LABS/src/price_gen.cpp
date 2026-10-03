#include <random>

#include "price_gen.h"
#include "data_types.h"
#include "conf.h"

void generate_price(std::array<booking, BOOKINGS_COUNT>& bookings) {
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(100,10000);
    
    for (int i = 0; i < BOOKINGS_COUNT; i++) {
        bookings[i].price = dist(engine);
    }
}