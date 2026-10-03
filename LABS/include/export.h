#ifndef EXPORT
#define EXPORT

#include <fstream>
#include <array>

#include "data_types.h"
#include "conf.h"

void writer(std::array<booking, BOOKINGS_COUNT> bookings, std::ofstream& file);

#endif