#include <iostream>
#include <array>
#include <cmath>

const int N = 14;

int jumpSearch(std::array<int, N>& arr, int target) {
    int block = static_cast<int>(std::sqrt(N));
    int prev = 0;
    int step = block;

    while (step < N && arr[step - 1] < target) {
        prev = step;
        step += block;
    }

    if (step > N) step = N;

    while (prev < step && arr[prev] < target) {
        prev++;
    }

    if (prev < N && arr[prev] == target)
        return prev;

    return -1;
}

int main() {
    std::array<int, N> arr = {-2,-1,0,1,2,3,4,5,6,9,14,15,19,20};

    // Проверка в диапозоне значений
    for (int target = -20; target < 20; target++) {
        int index = jumpSearch(arr, target);

        if (index != -1)
            std::cout << target << ' ' << index << "\n";
    }

    return 0;
}