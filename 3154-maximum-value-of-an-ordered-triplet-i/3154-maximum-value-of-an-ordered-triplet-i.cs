public class Solution {
    public long MaximumTripletValue(int[] nums) {
        var n = nums.Length;
        long ans = 0, dmax = 0, imax = 0;
        foreach (var num in nums) {
            ans = Math.Max(ans, dmax * num);
            dmax = Math.Max(dmax, imax - num);
            imax = Math.Max(imax, num);
        }
        return ans;
    }
}