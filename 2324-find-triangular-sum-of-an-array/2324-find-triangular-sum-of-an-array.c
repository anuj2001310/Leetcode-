int triangularSum(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; ++i) {
        int s = nums[i - 1];
        for (int j = i; j < numsSize; ++j) {
            int t = nums[j];
            nums[j] = (nums[j] + s) % 10;
            s = t;
        }
    }
    return nums[numsSize - 1];
}