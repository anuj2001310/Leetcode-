int largestCombination(int* candidates, int candidatesSize) {
    int arr[32] = {};
    int ans = INT_MIN;

    void dp(int n) {
        for (int i = 0; i < 31; ++i) {
            int mask = 1 << i;
            if (mask & n)
                arr[i]++;
            ans = fmax(ans, arr[i]);
        }
    }

    for (int i = 0; i < candidatesSize; ++i)
        dp(candidates[i]);

    return ans;
}