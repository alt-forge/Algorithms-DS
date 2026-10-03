#include <array>
#include <string>
#include <utility>

#include "passport_gen.h"
#include "data_types.h"
#include "conf.h"

const int PERMUTATION_SIZE = 10;

void generate_passports(std::array<booking, BOOKINGS_COUNT>& bookings) {
    std::array<int, PERMUTATION_SIZE> numbers = {0,1,2,3,4,5,6,7,8,9};
    if (PERMUTATION_SIZE == 0) return;

    int j, r, s;

    int i = 0;
    int k = 0;
    while ((i >= 0) and (k < BOOKINGS_COUNT)) {
        // Выводим перестановку
        std::string str = "";
        for (int j = 0; j < PERMUTATION_SIZE; j++) {
            str += std::to_string(numbers[j]);
        }
        bookings[k].passport = str;
        k++;

        // Поиск самого правого места
        i = PERMUTATION_SIZE - 2;
        while (i >= 0 and (numbers[i] >= numbers[i+1])) {
            --i;
        }

        if (i < 0) break; // Выход за начало массива

        // Поиск наименьшего справа от i-го элемента и большего его
        j = PERMUTATION_SIZE - 1;
        while (numbers[i] >= numbers[j]) {
            --j;
        }

        // Смена местами элементов перестановок
        std::swap(numbers[i], numbers[j]);
        r = PERMUTATION_SIZE - 1;
        s = i + 1;
        
        while (r > s) {
            std::swap(numbers[s], numbers[r]);
            --r;
            ++s;
        }
    
    }
}