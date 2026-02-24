class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            prefix[l]++;
            prefix[r + 1]--;
        }
        for (int i = 1; i <= n; ++i)
            prefix[i] += prefix[i - 1];
        for (int i = 0; i < n; ++i) {
            if (prefix[i] < nums[i])
                return false;
        }
        return true;
    }
};