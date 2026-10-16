#include <iostream>
#include <array>
#include <utility>

const int n = 8;

void cocktailSort(std::array<int, n>& arr) {
    int left = 0, right = n - 1;
    bool swapped = true;

    while (swapped) {
        swapped = false;

        for (int i = left; i < right; i++)
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        right--;

        for (int i = right; i > left; i--)
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        left++;
    }
}

int main() {
    std::array<int, n> arr = {8,19,2,7,13,28,4,0};

    cocktailSort(arr);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

}

/*
Best case: sorted
comparisons: 2(n-1)
exchanges: 0
time complexity: O(n)
memory complexity: O(1)

Worst case: reverse sorted
comparisons: ~ n^2 / 2
exchanges: ~ n^2 / 2
time complexity: O(n^2)
memory complexity: O(1)
*/