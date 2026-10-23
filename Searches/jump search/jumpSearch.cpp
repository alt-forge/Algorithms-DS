#include <array>
#include <cmath>

template <std::size_t N>
int jumpSearch(const std::array<int, N>& arr, int target) {
    if (N == 0)
        return -1;

    int block = static_cast<int>(std::sqrt(N));
    int prev = 0;
    int step = block;

    while (prev < static_cast<int>(N) &&
           step < static_cast<int>(N) &&
           arr[step - 1] < target) {
        prev = step;
        step += block;
    }

    if (step > static_cast<int>(N))
        step = static_cast<int>(N);

    while (prev < step && arr[prev] < target) {
        prev++;
    }

    if (prev < static_cast<int>(N) && arr[prev] == target)
        return prev;

    return -1;
}
