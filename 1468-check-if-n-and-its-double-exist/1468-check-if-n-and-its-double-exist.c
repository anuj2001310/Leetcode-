#include <stdbool.h>
#include <stdio.h>

bool checkIfExist(int* arr, int arrSize) {
    int i, j;
    for (i = 0; i < arrSize; i++) {
        for (j = i + 1; j < arrSize; j++) {
            if (arr[i] == 2 * arr[j] ||
                (arr[j] % 2 == 0 && arr[i] == arr[j] / 2)) {
                return true;
            }
        }
    }
    return false;
}
