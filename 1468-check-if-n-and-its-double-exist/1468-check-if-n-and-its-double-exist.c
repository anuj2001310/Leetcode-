#include <stdbool.h>
#include <stdio.h>

bool checkIfExist(int* arr, int arrSize) {
    int* record = (int*)calloc(2001, sizeof(int));
    int cnt = 0;
    for (cnt = 0; cnt < arrSize; cnt++) {
        record[arr[cnt] + 1000] += 1;
    }
    for (cnt = 0; cnt < arrSize; cnt++) {
        if (arr[cnt] == 0) {
            if (record[1000] > 1) {
                return 1;
            }
        } else if (abs(arr[cnt]) <= 500) {
            if (record[arr[cnt] * 2 + 1000]) {
                free(record);
                return 1;
            }
        }
    }
    free(record);
    return 0;
}
