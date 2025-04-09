class Solution {
    public int minOperations(int[] nums, int k) {
        int n = nums.length;
        int[] vis = new int[101];
        for (int x : nums) {
            if (x < k)
                return -1;
            else if (x > k)
                vis[x]++;
        }
        int cnt = 0;
        for (int i = 0; i < vis.length; ++i)
            if (vis[i] != 0)
                cnt++;
        
        return cnt;
    }
}