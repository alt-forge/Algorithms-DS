#include <iostream>
#include <array>
#include <utility>

const int n = 8;

int partition(std::array<int, n>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::array<int, n>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
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

/*
Best case: pivot splits the array into two equal halves every time
comparisons: n log n
exchanges: ~ n log n
time complexity: O(n log n)
memory complexity: O(log n)

Worst case: already sorted (or reverse sorted) with last-element pivot
comparisons: n(n - 1) / 2
exchanges: ~ n^2 / 2
time complexity: O(n^2)
memory complexity: O(n)
*/