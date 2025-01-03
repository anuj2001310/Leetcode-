int waysToSplitArray(int* nums, int numsSize) {
    long long int rsum = 0, lsum = 0;
    for (int i = 0; i < numsSize; i++)
        rsum += nums[i];
    int cn = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        lsum += nums[i];
        rsum -= nums[i];
        if (lsum >= rsum)
            cn++;
    }
    return cn;
}