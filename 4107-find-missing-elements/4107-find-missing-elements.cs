public class Solution {
    public IList<int> FindMissingElements(int[] nums) {
        int n = nums.Length;
        var vis = new bool[101];

        int min = Int32.MaxValue;
        int max = Int32.MinValue;
        for (var g = 0; g < n; g++) {
            min = Math.Min(min, nums[g]);
            max = Math.Max(max, nums[g]);
            vis[nums[g]] = true;
        }

        var ans = new List<int>();
        for (int i = min; i < max; ++i) {
            if (!vis[i])
            ans.Add(i);
        }
        return ans;
    }
}