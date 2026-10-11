#ifndef FIBSEARCH
#define FIBSEARCH

#include <array>

template <std::size_t N>
int fibSearch(std::array<int, N>& arr, int target) {
    int fibM2 = 0;
    int fibM1 = 1;
    int fibM  = fibM2 + fibM1;

    while (fibM < static_cast<int>(N)) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM  = fibM2 + fibM1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = offset + fibM2;
        if (i >= static_cast<int>(N))
            i = static_cast<int>(N) - 1;

        if (arr[i] < target) {
            fibM  = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        }
        else if (arr[i] > target) {
            fibM  = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        }
        else {
            return i;
        }
    }

    if (fibM1 && offset + 1 < static_cast<int>(N) && arr[offset + 1] == target)
        return offset + 1;

    return -1;
}

#endif