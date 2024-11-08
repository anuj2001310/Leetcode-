class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int b = (1 << maximumBit) - 1;
        int prefix = 0;
        for (auto& x : nums)
            prefix ^= x;

        for (int i = 0; i < n; ++i) {
            ans[i] = prefix ^ b;
            prefix ^= nums[n - i - 1];
        }
        return ans;
    }
};