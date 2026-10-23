#ifndef BINARYSEARCH
#define BINARYSEARCH

#include <array>
#include <vector>
#include <cstddef>

template <std::size_t N>
int binarySearch_arr(const std::array<int, N>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(N);

    while (left < right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] < target)
            left = middle + 1;
        else
            right = middle;
    }

    return left;
}

int binarySearch_vec(const std::vector<int>& arr, int target);

#endif