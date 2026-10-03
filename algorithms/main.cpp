#include <iostream>
#include <array>

#include "binarySearch.h"
#include "interpolationSearch.h"
#include "jumpSearch.h"
#include "fibSearch.h"

int main() {
    const int N = 14;
    std::array<int, N> arr = {-2,-1,0,1,2,3,4,5,6,9,14,15,19,20};

    // Проверка в диапозоне значений
    for (int target = -20; target < 20; target++) {
        int index = binarySearch(arr, target);
        //int index = interpolationSearch(arr, target);
        //int index = jumpSearch(arr, target);
        //int index = fibSearch(arr, target);

        if (index != -1)
            std::cout << target << ' ' << index << "\n";
    }

    return 0;
}