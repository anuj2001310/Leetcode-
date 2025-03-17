class Solution {
    public boolean divideArray(int[] nums) {
        int n = nums.length;
        boolean[] vis = new boolean[501];
        for (int x : nums)
            vis[x] = !vis[x];
        for (int i = 0; i < 501; i++)
            if (vis[i])
                return false;
        return true;
    }
}