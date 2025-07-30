class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int r = 1, l = 0, ans = 0;
        int temp = 0;
        int max = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        for (; r < n; r++) {
            if (nums[r] == nums[r - 1] and nums[r] == max)
                temp++;
            else
                temp = 1;
            ans = fmax(ans, temp);
        }
        return ans;
    }
};