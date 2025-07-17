class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(k + 1, vector<int>(k + 1, 0));
        vector<int> rem(n, 0);
        for (int i = 0; i < n; i++) {
            int rem = nums[i] % k;
            for (int j = 0; j < k; j++) {
                dp[rem][j] = max(dp[rem][j], 1 + dp[j][rem]);
                ans = max(ans, dp[rem][j]);
            }
        }

        return ans;
    }
};