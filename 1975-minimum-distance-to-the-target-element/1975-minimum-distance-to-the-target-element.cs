public class Solution {
    public int GetMinDistance(int[] nums, int target, int start) {
        int ans = Int32.MaxValue;
        int n = nums.Length;
        for (var  i = 0; i < n; i++) {
            if (nums[i] == target)
                ans = Math.Min(ans, Math.Abs(i - start));
        }
        return ans;
    }
}