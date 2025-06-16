int maximumDifference(int* nums, int numsSize) {
    int res = 0;
    int min = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        min = fmin(min, nums[i]);

        res = fmax(res, nums[i] - min);
    }
    return res == 0 ? -1 : res;
}