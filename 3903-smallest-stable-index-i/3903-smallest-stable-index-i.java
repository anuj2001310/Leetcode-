class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;
        int[] maxi = new int[n];
        int[] mini = new int[n];
        maxi[0] = nums[0];
        mini[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
            maxi[i] = Math.max(maxi[i - 1], nums[i]);
        
        for (int i = n - 2; i >= 0; i--)
            mini[i] = Math.min(mini[i + 1], nums[i]);
        
        /*for (int i = 0; i < n; i++)
            System.out.println(maxi[i] + " -> " + mini[i]);
        */
        for (int i = 0; i < n; i++) {
            if (maxi[i] - mini[i] <= k)
                ans = Math.min(ans, i);
        }
        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }
}