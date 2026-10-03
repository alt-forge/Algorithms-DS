#include <iostream>

int main() {
    const int N = 1000;
    int arr[N+1];

    //Инициализация массива
    for (int i = 0; i <= N; i++) {
        arr[i] = i;
    }
    
    int i = 2;
    int j;

    while (i*i <= N) {
        if (arr[i] != 0) {
            j = i*i;
            while (j <= N) {
                arr[j] = 0;
                j = j + i;
            }
        }
        i = i + 1;
    }

    
    //Вывод
    for (int i = 0; i<N; i++) {
        if (arr[i] != 0) {
            std::cout << arr[i];
        }
        std::cout << "\n";
    }
}