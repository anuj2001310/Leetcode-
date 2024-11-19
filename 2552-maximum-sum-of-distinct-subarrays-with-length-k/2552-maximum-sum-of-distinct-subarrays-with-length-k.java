class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long curr = 0;
        long ans = 0;
        int[] map = new int[100001];
        int l = 0;
        for (int r = 0; r < nums.length; r++) {
            curr += nums[r];
            if (++map[nums[r]] > 1) {
                while (map[nums[r]] > 1) {
                    curr -= nums[l];
                    --map[nums[l++]];
                }
            }
            if (r - l + 1 >= k) {
                if (r - l + 1 > k) {
                    curr -= nums[l];
                    --map[nums[l++]];
                }
                ans = Math.max(ans, curr);
            }
        }
        return ans;
    }
}