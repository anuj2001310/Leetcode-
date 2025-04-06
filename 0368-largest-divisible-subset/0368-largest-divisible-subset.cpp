class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n);
        vector<int> hash(n);
        hash[n - 1] = -1;
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            int maxi = 1;
            int pos = -1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0 && dp[j] + 1 > maxi) {
                    maxi = dp[j] + 1;
                    pos = j;
                }
            }
            dp[i] = maxi;
            hash[i] = pos;
        }
        int maxi = 0;
        int pos;
        for (int i = 0; i < n; i++) {
            if (maxi < dp[i]) {
                maxi = dp[i];
                pos = i;
            }
        }
        vector<int> ans;
        while (pos != -1) {
            ans.push_back(nums[pos]);
            pos = hash[pos];
        }
        return ans;
    }
};