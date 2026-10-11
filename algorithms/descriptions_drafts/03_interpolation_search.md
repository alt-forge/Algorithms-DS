# Интерполяционный поиск (`interpolationSearch`)

## 1. Название и классификация

**Интерполяционный поиск (Interpolation Search)** --- алгоритм поиска в
отсортированном массиве, который оценивает позицию искомого значения по
его величине относительно крайних элементов диапазона.

-   Класс алгоритма: поиск в упорядоченных данных.
-   Стратегия: вычисление предполагаемой позиции по интерполяционной
    формуле.
-   Тип результата: индекс найденного элемента или `-1`.
-   Средняя сложность при равномерном распределении значений: примерно
    `O(log log N)`.
-   Худшая сложность: `O(N)`.

## 2. Идея

Вместо проверки строго средней позиции алгоритм оценивает, где значение
должно находиться. Если искомое число ближе к минимальному значению
диапазона, проверяемая позиция будет ближе к его началу; если ближе к
максимальному --- к концу.

После проверки позиции алгоритм исключает часть диапазона, в которой
искомого значения быть не может.

Если значения на обеих границах одинаковы, делить на разность нельзя.
Поэтому этот случай обрабатывается отдельно.

## 3. Входные и выходные данные

**Вход:** - `arr` --- массив целых чисел, отсортированный по
возрастанию; - `target` --- искомое целое число.

**Выход:** - индекс одного из совпадений; - `-1`, если значение не
найдено.

**Условия:** - массив должен быть отсортирован по возрастанию; - пустой
массив допустим; - эффективность зависит от распределения значений; -
при дубликатах функция не гарантирует первое вхождение.

## 4. Псевдокод

``` text
left = 0
right = N - 1

пока диапазон не пуст и target находится между крайними значениями:
    если arr[left] == arr[right]:
        если arr[left] == target:
            вернуть left
        иначе:
            вернуть -1

    вычислить предполагаемую позицию pos
    ограничить pos диапазоном [left, right]

    если arr[pos] == target:
        вернуть pos
    если arr[pos] < target:
        left = pos + 1
    иначе:
        right = pos - 1

вернуть -1
```

## 5. Визуализация

*Место для собственной визуализации алгоритма.*

## 6. Анализ сложности

-   Лучший случай: `O(1)`.
-   Средний случай при близком к равномерному распределении: примерно
    `O(log log N)`.
-   Худший случай: `O(N)`.
-   Дополнительная память: `O(1)`.

## 7. Реализация

``` cpp
#ifndef INTERPOLATIONSEARCH
#define INTERPOLATIONSEARCH

#include <array>
#include <cstddef>

template <std::size_t N>
int interpolationSearch(const std::array<int, N>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(N) - 1;

    while (left <= right &&
           target >= arr[left] &&
           target <= arr[right]) {

        if (arr[left] == arr[right]) {
            if (arr[left] == target)
                return left;
            return -1;
        }

        long long numerator =
            static_cast<long long>(target) - arr[left];
        long long denominator =
            static_cast<long long>(arr[right]) - arr[left];

        int pos = left + static_cast<int>(
            static_cast<double>(right - left) *
            static_cast<double>(numerator) /
            static_cast<double>(denominator)
        );

        if (pos < left) pos = left;
        if (pos > right) pos = right;

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }

    return -1;
}

#endif
```

## 8. Примеры использования

``` cpp
#include <array>
#include <iostream>
#include "interpolation_search.hpp"

int main() {
    const std::array<int, 6> numbers = {10, 20, 30, 40, 50, 60};
    const std::array<int, 4> repeated = {5, 5, 5, 5};

    std::cout << interpolationSearch(numbers, 40) << '\n'; // 3
    std::cout << interpolationSearch(numbers, 45) << '\n'; // -1
    std::cout << interpolationSearch(repeated, 5) << '\n'; // 0
}
```

В первом примере `40` находится по индексу `3`. Во втором `45`
отсутствует. В третьем все значения одинаковы, поэтому функция корректно
возвращает `0`.
