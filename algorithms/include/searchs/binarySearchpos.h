#ifndef BINARYSEARCHPOS
#define BINARYSEARCHPOS

#include <array>

template <std::size_t N>
int binarySearchpos(std::array<int, N>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(N);

    while (left < right) {
        int middle = static_cast<int>(left + (right - left) / 2);
        if (target > arr[middle]) left = middle + 1;
        else right = middle;
    }
    return left;
}

#endif