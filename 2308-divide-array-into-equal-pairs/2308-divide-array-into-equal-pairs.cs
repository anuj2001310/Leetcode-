public class Solution {
    public bool DivideArray(int[] nums) {
        var n = nums.Length;
        var vis = new bool[501];
        foreach (var num in nums)
            vis[num] = !vis[num];
        foreach (var t in vis)
            if (t)
                return false;
        return true;
    }
}