public class Solution {
    public int MaximumBeauty(int[] nums, int k) {
        Array.Sort(nums);
        var d = 2 * k;
        var l = 0;
        foreach (var n in nums) {
            if (nums[l] + d < n)
                l++;
        }
        return nums.Length - l;
    }
}