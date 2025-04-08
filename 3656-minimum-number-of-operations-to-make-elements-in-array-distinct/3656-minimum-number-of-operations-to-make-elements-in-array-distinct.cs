public class Solution {
    public int MinimumOperations(int[] nums) {
        int n = nums.Length;
        var map = new bool[101];
        for (int i = n - 1; i >= 0; --i) {
            if (map[nums[i]])
                return (int)Math.Ceiling((double) (i + 1) / 3);
            map[nums[i]] = true;
        }
        return 0;
    }
}