public class Solution {
    public int AbsDifference(int[] nums, int k) {
        var n = nums.Length;
        Array.Sort(nums);
        int s = 0, f = 0;

        for (int i = 0; i < k; ++i) {
            s += nums[i];
            f += nums[n - i - 1];
        }

        return f - s;
    }
}