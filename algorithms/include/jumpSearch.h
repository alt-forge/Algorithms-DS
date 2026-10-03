#ifndef JUMPSEARCH
#define JUMPSEARCH

#include <array>
#include <cmath>

template <std::size_t N>
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

#endif