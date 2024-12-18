/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int count;
} Heap;

static int compareHeap(const void* x, const void* y) {
    return ((Heap*)y)->count - ((Heap*)x)->count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = 0;
    int hash[20001] = {0};
    int i, c = 0;

    for (i = 0; i < numsSize; i++) {
        hash[nums[i] + 10000]++;
    }

    for (i = 0; i < 20001; i++) {
        if (hash[i] > 0)
            c++;
    }

    Heap heap[c];
    c = 0;
    for (i = 0; i < 20001; i++) {
        if (hash[i] > 0) {
            heap[c].num = i - 10000;
            heap[c++].count = hash[i];
        }
    }

    qsort(heap, c, sizeof(Heap), compareHeap);

    int* res = (int*)calloc(sizeof(int), k);
    for (i = 0; i < k; i++) 
        res[(*returnSize)++] = heap[i].num;

    return res;
}