class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] q) {
        int l = nums.length;
        int[] arr = new int[l];
        for (int i = 1; i < l; ++i)
            arr[i] = (((nums[i] ^ nums[i - 1]) & 1) != 0) ? arr[i - 1] : i;
            
        int q_len = q.length;
        boolean[] ans = new boolean[q_len];
        for (int i = 0; i < q_len; ++i) {
            int f = q[i][0];
            int t = q[i][1];
            ans[i] = arr[t] <= f;
        }
        return ans;
    }
}