#ifndef PASSPORT_GEN_H
#define PASSPORT_GEN_H

#include <array>

#include "data_types.h"
#include "conf.h"

void generate_passports(std::array<booking, BOOKINGS_COUNT>& bookings);

#endif