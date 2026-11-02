#include <vector>

#include "searches.h"

#include "calcDate.h"

int linearSearch_arr(booking* arr, int target, int filled) {
    for (int k = 0; k < filled; ++k) {
        int d = calcDate(arr[k].date_booking);
        if (d >= target) return k;
    }
    return filled;
}

int linearSearch_vec(const std::vector<booking>& vec, int target) {
    for (int k = 0; k < static_cast<int>(vec.size()); ++k) {
        int d = calcDate(vec[k].date_booking);
        if (d >= target) return k;
    }
    return static_cast<int>(vec.size());
}

int interpolationSearch_arr(booking* arr, int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int lval = calcDate(arr[left].date_booking);
        int rval = calcDate(arr[right].date_booking);

        if (target < lval || target > rval) break;

        if (lval == rval) {
            if (lval == target) return left;
            return -1;
        }

        int pos = left + static_cast<int>(
            (static_cast<double>(right - left) / (rval - lval)) *
            (target - lval)
        );

        if (pos < left) pos = left;
        if (pos > right) pos = right;

        int pval = calcDate(arr[pos].date_booking);

        if (pval == target) return pos;
        else if (pval < target) left = pos + 1;
        else right = pos - 1;
    }

    return -1;
}

int interpolationSearch_vec(const std::vector<booking>& vec, int target) {
    int left = 0;
    int right = static_cast<int>(vec.size()) - 1;

    while (left <= right) {
        int lval = calcDate(vec[left].date_booking);
        int rval = calcDate(vec[right].date_booking);

        if (target < lval || target > rval) break;

        if (lval == rval) {
            if (lval == target) return left;
            return -1;
        }

        int pos = left + static_cast<int>(
            (static_cast<double>(right - left) / (rval - lval)) *
            (target - lval)
        );

        if (pos < left) pos = left;
        if (pos > right) pos = right;

        int pval = calcDate(vec[pos].date_booking);

        if (pval == target) return pos;
        else if (pval < target) left = pos + 1;
        else right = pos - 1;
    }

    return -1;
}

int barrierSearch_arr(booking* arr, int n, int target) {
    if (n <= 0) return -1;

    int* keys = new int[n];
    for (int i = 0; i < n; ++i)
        keys[i] = calcDate(arr[i].date_booking);

    int last = keys[n - 1];
    keys[n - 1] = target;

    int i = 0;
    while (keys[i] != target)
        ++i;

    keys[n - 1] = last;
    delete[] keys;

    if (i < n - 1 || last == target)
        return i;
    return -1;
}

int barrierSearch_vec(const std::vector<booking>& vec, int target) {
    int n = static_cast<int>(vec.size());
    if (n <= 0) return -1;

    int* keys = new int[n];
    for (int i = 0; i < n; ++i)
        keys[i] = calcDate(vec[i].date_booking);

    int last = keys[n - 1];
    keys[n - 1] = target;

    int i = 0;
    while (keys[i] != target)
        ++i;

    keys[n - 1] = last;
    delete[] keys;

    if (i < n - 1 || last == target)
        return i;
    return -1;
}