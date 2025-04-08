class Solution {
    public int minimumOperations(int[] nums) {
        int n = nums.length;
        boolean[] vis = new boolean[101];

        for (int i = n - 1; i >= 0; i--) {
            if (vis[nums[i]])
                return (int)Math.ceil((double)(i + 1) / 3);
            vis[nums[i]] = true;
        }
        return 0;
    }
}