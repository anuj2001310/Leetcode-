class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto n = nums.size();
        int l = 0, r = 0, ans = 0;
        int xero_cnt = 0;
        for (; r < n; r++) {
            if (nums[r] == 0)
                xero_cnt++;
            while (xero_cnt > 1)
                xero_cnt -= (nums[l] == 0), l++;

            ans = fmax(ans, r - l);
        }
        return ans;
    }
};