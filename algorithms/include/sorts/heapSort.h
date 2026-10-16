#include <iostream>
using namespace std;

// Просеивание вниз: восстанавливает max-heap в поддереве с корнем i
void heapify(int a[], int n, int i) {
    int largest = i;          // предполагаем, что корень — наибольший
    int l = 2 * i + 1;        // левый ребёнок
    int r = 2 * i + 2;        // правый ребёнок

    // сравниваем с левым
    if (l < n && a[l] > a[largest])
        largest = l;

    // сравниваем с правым
    if (r < n && a[r] > a[largest])
        largest = r;

    // если наибольший — не корень, меняем и продолжаем вниз
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    // ЭТАП 1: построение max-heap (снизу вверх)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // ЭТАП 2: извлечение максимумов
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);   // максимум → в конец
        heapify(a, i, 0);   // восстановить кучу размера i
    }
}

int main() {
    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(a) / sizeof(a[0]);

    heapSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    // Вывод: 1 2 3 4 7 8 9 10 14 16
}