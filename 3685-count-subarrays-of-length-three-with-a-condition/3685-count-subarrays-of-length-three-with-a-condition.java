class Solution {
    public int countSubarrays(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (2 * (nums[i - 1] + nums[i + 1]) == nums[i])
                cnt++;
        }
        return cnt;
    }
}