class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int r = 0; r < n; r++)
            ans ^= nums[r];
        if (ans != 0)
            return n;

        for (auto& num : nums)
            if (num != 0)
                return n - 1;
        return 0;
    }
};