/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int index;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int* lexicographicallySmallestArray(int* nums, int n, int limit, int* returnSize) {
    Pair* help = (Pair*)malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        help[i].value = nums[i];
        help[i].index = i;
    }
    
    qsort(help, n, sizeof(Pair), compare);
    
    int* res = (int*)malloc(n * sizeof(int));
    int prev = INT_MIN;
    int* pos = (int*)malloc(n * sizeof(int));
    int pos_count = 0;
    
    for (int s = 0, e = 0; e < n;) {
        pos[pos_count++] = help[e].index;
        prev = help[e].value;
        e++;
        
        if (e == n || help[e].value - prev > limit) {
            qsort(pos, pos_count, sizeof(int), compare);
            for (int i = 0; i < pos_count; i++) {
                res[pos[i]] = help[s].value;
                s++;
            }
            pos_count = 0;
        }
    }
    
    free(help);
    free(pos);
    *returnSize = n;
    return res;
}

