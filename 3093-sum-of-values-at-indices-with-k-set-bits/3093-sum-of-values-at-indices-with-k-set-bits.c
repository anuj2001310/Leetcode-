int sumIndicesWithKSetBits(int* nums, int numsSize, int k) {
    int bits(int num) {
        int b = 0;
        while (num) {
            num &= (num - 1);
            b++;
        }
        return b;
    }

    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (bits(i) == k)
            sum += nums[i];
    }
    return sum;
}