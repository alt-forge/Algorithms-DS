#include <vector>
#include "binarySearch.h"

int binarySearch_vec(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size());

    while (left < right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] < target)
            left = middle + 1;
        else
            right = middle;
    }

    return left;
}