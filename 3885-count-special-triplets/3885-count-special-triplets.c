const int MOD = 1e9 + 7;
int specialTriplets(int* nums, int n) {
    int max = 0;
    for (int i = 0; i < n; ++i)
        if (max < nums[i])
            max = nums[i];
    int maxSize = 2 * max + 1;

    // printf("%d", maxSize);
    long long left[maxSize] = {};
    long long right[maxSize] = {};

    for (int i = 0; i < n; ++i)
        right[nums[i]]++;

    long long ans = 0;

    for (int j = 0; j < n; j++) {
        right[nums[j]]--;
        int val = 2 * nums[j];
        long long lval = left[val];
        long long rval = right[val];

        ans = (ans + (lval * rval)) % MOD;

        left[nums[j]]++;
    }
    return (int)ans;
}