class Solution {
    public int waysToSplitArray(int[] nums) {
        long lsum = 0, rsum = 0;
        int n = nums.length;
        for (int x : nums)
            rsum += x;

        int c = 0;
        for (int u = 0; u < n - 1; u++) {
            lsum += nums[u];
            rsum -= nums[u];
            if (lsum >= rsum)
                c++;
        }
        return c;
    }
}