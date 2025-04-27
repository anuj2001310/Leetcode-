public class Solution {
    public int CountSubarrays(int[] nums) {
        var n = nums.Length;
        var cnt = 0;
        for (int i = 1; i < n  - 1; ++i) {
            if (2 * (nums[i - 1] + nums[i + 1]) == nums[i])
                cnt++;
        }
        return cnt;
    }
}