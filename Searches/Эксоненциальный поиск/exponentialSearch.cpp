#include <iostream>
#include <array>
#include <algorithm>

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

template <std::size_t N>
int exponentialSearch(const std::array<int, N>& arr, int target) {
    const int n = static_cast<int>(N);
    if (n == 0) return -1;

    if (arr[0] == target) return 0;

    int bound = 1;
    while (bound < n && arr[bound] < target) {
        bound *= 2;
    }

    int left = bound / 2;
    int right = std::min(bound, n - 1);

    return binarySearch(arr, left, right, target);
}

int main() {
    std::array<int, 11> arr = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90, 100};
    int target = 10;

    int result = exponentialSearch(arr, target);

    if (result != -1)
        std::cout << "Элемент найден по индексу: " << result << std::endl;
    else
        std::cout << "Элемент не найден" << std::endl;

    return 0;
}