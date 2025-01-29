/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int find(int* dsu, int v) {
    if (dsu[v] == -1)
        return v;
    return dsu[v] = find(dsu, dsu[v]);
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int n = edgesSize;
    int* dsu = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) 
        dsu[i] = -1;


    for (int i = 0; i < n; i++) {
        int parent_x = find(dsu, edges[i][0]);
        int parent_y = find(dsu, edges[i][1]);

        if (parent_x == parent_y) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = edges[i][0];
            result[1] = edges[i][1];
            free(dsu);
            *returnSize = 2;
            return result;
        } 
        else
            dsu[parent_x] = parent_y;
    }

    free(dsu);
    return NULL;
}
