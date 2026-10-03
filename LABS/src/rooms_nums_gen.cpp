#include <array>

#include "rooms_nums_gen.h"
#include "conf.h"

void generate_rooms_nums(std::array<booking, BOOKINGS_COUNT>& bookings) {
    for (int i = 0; i < BOOKINGS_COUNT; i++) {
        bookings[i].rooms_nums.insert(0);
    }
}