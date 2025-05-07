#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int cmp(const void* a, const void* b) { 
    return *(int*)b - *(int*)a;
}

long long maxSum(int** grid, int gridSize, int* gridColSize, int* limits, int limitsSize, int k) {
    int* r = (int*)calloc(sizeof(int), 250000);
    int idx = 0;

    for (int i = 0; i < gridSize; i++)
        qsort(grid[i], *gridColSize, sizeof(int), cmp);

    for (int i = 0; i < limitsSize; i++) {
        for (int j = 0; j < limits[i]; j++)
            r[idx++] = (grid[i][j]);
    }

    qsort(r, idx, sizeof(int), cmp);

    ll sum = 0;
    for (int i = 0; i < k; i++)
        sum += r[i];

    free(r);

    return sum;
}