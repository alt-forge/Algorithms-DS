#ifndef BINARYSEARCH
#define BINARYSEARCH

#include <array>

template <std::size_t N>
int binarySearch(std::array<int, N>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(N)-1;

    while (left <= right) {
        int middle = static_cast<int>(left + (right - left) / 2);
        
        if (arr[middle] == target) return middle;
        else {
            if (target < arr[middle]) right = middle - 1;
            else left = middle + 1;
        }
    }
    return -1;
}

#endif