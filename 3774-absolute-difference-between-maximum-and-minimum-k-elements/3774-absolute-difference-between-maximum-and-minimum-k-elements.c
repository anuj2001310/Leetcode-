int cmp(const void* a, const void* b) { 
    return *((int*)a) - *((int*)b);
}

int absDifference(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int s = 0, f = 0;
    for (int i = 0; i < k; ++i) {
        s += nums[i];
        f += nums[numsSize - i - 1];
    }
    return f - s;
}