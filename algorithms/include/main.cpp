#include <iostream>
#include <array>

#include "binarySearch.h"
#include "binarySearchpos.h"
#include "interpolationSearch.h"
#include "jumpSearch.h"
#include "fibSearch.h"

int main() {
    const int N = 14;
    std::array<int, N> arr = {-2,-1,0,1,2,3,4,5,6,9,14,15,19,20};

    // Проверка в диапозоне значений
    int target = 8;
    int index = binarySearchpos(arr, target);
    //int index = binarySearch(arr, target);
    //int index = interpolationSearch(arr, target);
    //int index = jumpSearch(arr, target);
    //int index = fibSearch(arr, target);

    std::cout << target << " " << index << " " << arr[index];
    return 0;
}