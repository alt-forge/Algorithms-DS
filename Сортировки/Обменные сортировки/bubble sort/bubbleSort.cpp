#include <iostream>
#include <array>
#include <utility>

const int n = 8;

void bubbleSort(std::array<int,n>& arr) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    std::array<int, n> arr = {8,19,2,7,13,28,4,0};

    bubbleSort(arr);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

}

/*
Best case: sorted
comparisons: n(n-1) / 2
exchanges: 0
time complexity: O(n^2)
memory complexity: O(1)

Worst case reverse sorted:
comparisons: n(n-1) / 2
exchanges: n(n - 1) / 2
time complexity: O(n^2)
memory complexity: O(1)
*/

