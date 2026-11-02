#include "remove_arr_vec.h"
#include "data_types.h"

int remove_arr(booking* arr, int n, int idx) {
    if (idx < 0 || idx >= n) return n;

    for (int i = idx; i < n - 1; ++i)
        arr[i] = arr[i + 1];

    return n - 1;
}

bool remove_vec(std::vector<booking>& vec, int idx) {
    if (idx < 0 || idx >= static_cast<int>(vec.size())) return false;
    vec.erase(vec.begin() + idx);
    return true;
}
