class Solution {
    public long maxProduct(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        long ans = 1_00_000;
        long f = -ans, s = -ans;
        for (int r = 0; r < n; ++r) {
            if (nums[r] != 0)
                cnt++;
            if (Math.abs(nums[r]) >= f) {
                s = f;
                f = Math.abs(nums[r]);
            }
            else if (Math.abs(nums[r]) > s && Math.abs(nums[r]) != f)
                s = Math.abs(nums[r]);
        }
        if (cnt <= n / 3)
            return 0;

        return Math.abs(f * s * ans);
    }
}