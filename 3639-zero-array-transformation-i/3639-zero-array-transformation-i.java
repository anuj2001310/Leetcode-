class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] gfg = new int[n + 1];
        
        for (int[] q : queries) {
            int l = q[0];
            int r = q[1];
            gfg[l]++;
            gfg[r + 1]--;
        }
        
        for (int i = 1; i <= n; ++i)
            gfg[i] += gfg[i - 1];
        for (int i = 0; i < n; ++i) {
            if (gfg[i] < nums[i])
                return false;
        }
        return true;
    }
}