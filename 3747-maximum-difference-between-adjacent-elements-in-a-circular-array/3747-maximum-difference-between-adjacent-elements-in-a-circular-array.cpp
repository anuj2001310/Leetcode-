class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = numeric_limits<int>::min();
        for (int i = 1; i < n; i++) {
            int val = fabs(nums[i - 1] - nums[i]);
            ans = fmax(ans, val);
        }
        ans = fmax(ans, fabs(nums[0] - nums[n - 1]));
        return ans;
    }
};