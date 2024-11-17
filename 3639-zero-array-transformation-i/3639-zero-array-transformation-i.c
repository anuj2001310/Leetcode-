bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int n = numsSize;
    int delta[n + 1] = {};
    for (int i = 0; i < queriesSize; ++i) {
        int l = queries[i][0];
        int r = queries[i][1];
        delta[l]++;
        delta[r + 1]--;
    }
    
    for (int i = 1; i <= n; ++i)
        delta[i] += delta[i - 1];
    
    for (int i = 0; i < n; ++i) {
        if (delta[i] < nums[i])
            return false;
    }
    return true;
}