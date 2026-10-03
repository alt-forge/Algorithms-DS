#include <array>
#include <string>
#include <utility>

#include "passport_gen.h"

const int PERMUTATION_SIZE = 10;

std::array<int, PERMUTATION_SIZE> numbers = {0,1,2,3,4,5,6,7,8,9};
bool p_done = false;

std::string nextPassport() {
    if (p_done) return "";

    // Выводим перестановку
    std::string str = "";
    for (int j = 0; j < PERMUTATION_SIZE; j++) {
        str += std::to_string(numbers[j]);
    }

    // Поиск самого правого места
    int i = PERMUTATION_SIZE - 2;
    while (i >= 0 and (numbers[i] >= numbers[i+1])) {
        --i;
    }

    if (i < 0) {
        p_done = true;
        return str;
    }

    // Поиск наименьшего справа от i-го элемента и большего его
    int j = PERMUTATION_SIZE - 1;
    while (numbers[i] >= numbers[j]) {
        --j;
    }

    // Смена местами элементов перестановок
    std::swap(numbers[i], numbers[j]);
    int r = PERMUTATION_SIZE - 1;
    int s = i + 1;

    while (r > s) {
        std::swap(numbers[s], numbers[r]);
        --r;
        ++s;
    }

    return str;
}