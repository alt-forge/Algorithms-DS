#include <iostream>
#include <array>
#include <cmath>

const int N = 10;

int jumpSearch(std::array<int, N>& arr, int target) {
    if (N <= 0) return -1;

    int block = static_cast<int>(std::sqrt(N));
    int step = block;
    int prev = 0;

    while (arr[std::min(step,N) - 1] < target) {
        prev = step;
        step += block;
        if (prev >= N) return -1;
    }

    while (arr[prev] < target) {
        prev++;
        if (arr[prev] == target) return prev;
    }
    
    return -1;
}

int main() {
    std::array<int, N> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    int target;
    for (int target = 0; target < 100; target++) {
        int index = jumpSearch(arr, target);

        if (index != -1)
            std::cout << "Элемент " << target << " найден по индексу " << index << "\n";
        else
            std::cout << "Элемент " << target << " не найден\n";
    }
    return 0;
}