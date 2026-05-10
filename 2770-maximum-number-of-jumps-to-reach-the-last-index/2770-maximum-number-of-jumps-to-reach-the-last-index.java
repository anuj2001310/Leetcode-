class Solution {
    public int maximumJumps(int[] nums, int target) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -2);
        return helper(0, nums, target, ans);
    }

    public static int helper(int index, int[] nums, int target, int[] dp) {
        int len = nums.length;
        if (index == len - 1)
            return 0;
        if (dp[index] != -2)
            return dp[index];
        int maxJump = -1;
        for (int i = index + 1; i < len; i++) {
            if (Math.abs(nums[index] - nums[i]) <= target) {
                int cur = helper(i, nums, target, dp);
                if (cur != -1)
                    maxJump = Math.max(maxJump, cur + 1);

            }
        }
        return dp[index] = maxJump;
    }
}