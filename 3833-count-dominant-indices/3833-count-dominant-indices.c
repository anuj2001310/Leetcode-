int dominantIndices(int* nums, int n) {
    int cnt = 0;
    uint s = 0;
    for (int i = 0; i < n; ++i)
        s += nums[i];
    for (int i = 0; i < n - 1; ++i) {
        s -= nums[i];
        int l = n - i - 1;
        cnt += ((long long)nums[i] > (long long)(s / l));
    }
    return cnt;
}