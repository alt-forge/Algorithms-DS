#include <iostream>
#include <array>
#include <utility>

const int n = 8;

int partition(std::array<int, n>& arr, int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);

        if (i >= j)
            return j;

        std::swap(arr[i], arr[j]);
    }
}

void quickSort(std::array<int, n>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    std::array<int, n> arr = {8,19,2,7,13,28,4,0};

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
}