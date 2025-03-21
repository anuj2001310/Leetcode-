class Solution {
    private boolean memo(int[]  nums, int[][] dp, int sum, int idx) {
        if (sum == 0)
            return true;
        
        if (idx >= nums.length)
            return false;
        
        if (dp[idx][sum] != -1)
            return (dp[idx][sum] == 1 ? true : false);
        
        boolean pick = false, non_pick = false;
        if (nums[idx] <= sum)
            pick = memo(nums, dp, sum - nums[idx], idx + 1);
        
        non_pick = memo(nums, dp, sum, idx + 1);

        dp[idx][sum] = ((pick || non_pick) ? 1 : 0);
        
        return dp[idx][sum] == 1 ? true : false;
    }
    public boolean canPartition(int[] nums) {
        int n = nums.length, sum = 0;
        for (int num : nums)
            sum += num;
        if ((sum & 1) != 0)
            return false;

        int[][] dp = new int[n][(sum >> 1) + 1];

        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);
            
        return memo(nums, dp, sum >> 1, 0);
    }
}