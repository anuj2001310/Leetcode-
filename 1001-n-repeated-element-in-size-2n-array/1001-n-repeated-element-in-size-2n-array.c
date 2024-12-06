int repeatedNTimes(int* nums, int numsSize) {
    int n = numsSize >> 1;
    bool* hash = (bool*)calloc(sizeof(bool), 10001);
    for (uint i = 0; i < numsSize; ++i) {
        if (hash[nums[i]]) {
            free(hash);
            return nums[i];
        } else
            hash[nums[i]] = true;
    }
    return -1;
}