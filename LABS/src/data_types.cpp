#include <string>
#include <ostream>

#include "data_types.h"

std::ostream& operator<<(std::ostream& os, const date& d) {
    os << d.day << '.' << d.month << '.' << d.year;
    return os;
}