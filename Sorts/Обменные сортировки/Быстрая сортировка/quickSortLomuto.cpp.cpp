#include <iostream>
#include <array>
#include <utility>

const int n = 11;

template <std::size_t N>
void printArray(const std::array<int, N>& arr) {
    std::cout << "[ ";
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << arr[i];
        if (i + 1 < N) std::cout << ", ";
    }
    std::cout << " ]\n";
}

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
    printArray(arr);
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
    std::array<int, n> arr = {79,80,2,5,98,15,21,14,0,55,11};

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

}