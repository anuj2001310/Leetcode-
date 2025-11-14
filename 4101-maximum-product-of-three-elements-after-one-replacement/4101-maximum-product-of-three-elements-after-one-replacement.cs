public class Solution {
    public long MaxProduct(int[] nums) {
        int n = nums.Length;
        int cnt = 0;
        long ans = 1_00_000;
        long f = -ans, s = -ans;
        for (int r = 0; r < n; ++r) {
            if (nums[r] != 0)
                cnt++;
            if (Math.Abs(nums[r]) >= f) {
                s = f;
                f = Math.Abs(nums[r]);
            }
            else if (Math.Abs(nums[r]) > s && Math.Abs(nums[r]) != f)
                s = Math.Abs(nums[r]);
        }
        if (cnt <= n / 3)
            return 0;

        return Math.Abs(f * s * ans);
    }
}