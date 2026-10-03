#include <array>

#include "date_gen.h"
#include "data_types.h"
#include "conf.h"

void generate_date(std::array<booking, BOOKINGS_COUNT>& bookings) {
    for (int i = 0; i < BOOKINGS_COUNT; i++) {
        bookings[i].date_booking.day = 0;
        bookings[i].date_booking.month = 0;
        bookings[i].date_booking.year = 0;
    }
}
