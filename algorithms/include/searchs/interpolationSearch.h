#ifndef INTERPOLATIONSEARCH
#define INTERPOLATIONSEARCH

#include <array>

template <std::size_t N>
int interpolationSearch(const std::array<int, N>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(N) - 1;

    while (left <= right &&
           target >= arr[left] &&
           target <= arr[right]) {

        if (arr[left] == arr[right]) {
            if (arr[left] == target)
                return left;
            return -1;
        }

        int pos = left + static_cast<int>(
            (static_cast<double>(right - left) /
             (arr[right] - arr[left])) *
            (target - arr[left])
        );

        if (pos < left) pos = left;
        if (pos > right) pos = right;

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1;
}

#endif