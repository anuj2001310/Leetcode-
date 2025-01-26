int countPartitions(int* nums, int numsSize) {
    int cnt = 0, sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];
    int leftsum = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        leftsum += nums[i];
        if ((abs(sum - 2 * leftsum) & 1) == 0)
            cnt++;
    }
    return cnt;
}