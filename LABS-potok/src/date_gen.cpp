#include "data_types.h"

#include "date_gen.h"

int xorshift_range(int lo, int hi) {
    static unsigned int state = 12345;
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    unsigned int range = (unsigned int)(hi - lo + 1);
    return lo + (int)(state % range);
}

date nextDate() {
    date d;
    d.year  = xorshift_range(2000, 2025);
    d.month = xorshift_range(1, 12);
    d.day   = xorshift_range(1, 28);
    return d;
}