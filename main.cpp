#include <iostream>

int main() {
    char b[5] = {'a', 'b', 'c', 'd', 'e'};
    int arr[5];

    for (int i = 0; i<5; i++) {
        arr[i] = 0;
    }

    int i;

    while (arr[4] != 1) {
        for (int j = 0; j<5; j++) {
            if (true) {
                std::cout << arr[j];
            }
        }
        std::cout << std::endl;
        i = 0;
        while (arr[i] == 1)
        {
            arr[i] = 0;
            i += 1;
        }
        arr[i] = 1;
    }

    return 0;
}