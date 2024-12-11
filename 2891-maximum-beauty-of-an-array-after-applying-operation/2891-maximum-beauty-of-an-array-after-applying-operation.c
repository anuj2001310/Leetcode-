int cmp (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maximumBeauty(int* nums, int numsSize, int k) {
    qsort (nums, numsSize, sizeof(int), cmp);
    int d = 2 * k, l = 0;
    for (uint i = 0; i < numsSize; ++i) {
        if (nums[l] + d < nums[i])
            l++;
        
    }
    return numsSize - l;
}