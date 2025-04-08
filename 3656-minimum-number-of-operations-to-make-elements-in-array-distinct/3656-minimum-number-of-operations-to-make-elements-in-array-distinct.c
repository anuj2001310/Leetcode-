int minimumOperations(int* nums, int numsSize) {
    bool freq[101] = {};
    for (int i = numsSize - 1; i >= 0; i--) {
        if (freq[nums[i]])
            return ceil((double) (i + 1) / 3);
        freq[nums[i]] = true;
    }
    return 0;
}