class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int ans = Integer.MIN_VALUE;
        for (int i = 1; i < n; ++i) {
            int val = Math.abs(nums[i - 1] - nums[i]);
            ans = Math.max(ans, val);
        }
        ans = Math.max(ans, Math.abs(nums[0] - nums[n - 1]));
        return ans;
    }
}