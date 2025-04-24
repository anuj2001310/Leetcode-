int maximumPossibleSize(int* nums, int numsSize) {
    int cnt = 1;
    int num = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] >= num) {
            cnt++;
            num = nums[i];
        }
    }
    return cnt;
}