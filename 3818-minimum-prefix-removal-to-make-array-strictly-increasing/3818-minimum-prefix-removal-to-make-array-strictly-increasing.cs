public class Solution {
    public int MinimumPrefixLength(int[] nums) {
        var n = nums.Length;
        for (var i = n - 1; i > 0; i--) {
            if (nums[i] <= nums[i - 1])
                return i;
        }
        return 0;
    }
}