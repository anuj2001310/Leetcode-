int repeatedNTimes(int* nums, int numsSize) {
    int n = numsSize >> 1;
    int* hash = (int*)calloc(sizeof(int), 10001);
    for (uint i = 0; i < numsSize; ++i) {
        hash[nums[i]]++;
        if (hash[nums[i]] >= n) {
            free(hash);
            return nums[i];
        }
    }
    return -1;
}