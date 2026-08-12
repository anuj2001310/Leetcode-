public class Solution {
    public int MaxSubarrayLength(int[] nums, int k) {
        int n = nums.Length;
        var map = new Dictionary<int, int>();
        int l = 0, r = 0, ans = Int32.MinValue;

        for (; r < n; r++) {
            if (map.ContainsKey(nums[r]))
                map[nums[r]]++;
            else
                map[nums[r]] = 1;
            
            while (map[nums[r]] > k)
                map[nums[l++]]--;
            
            ans = Math.Max(ans, r - l + 1);
        }
        return ans;
    }
}