class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] dp = new int[n];
        int[] hash = new int[n];
        hash[n - 1] = -1;
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            int maxi = 1;
            int pos = -1;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0 && dp[j] + 1 > maxi) {
                    maxi = dp[j] + 1;
                    pos = j;
                }
            }
            dp[i] = maxi;
            hash[i] = pos;
        }
        int maxi = 0;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (maxi < dp[i]) {
                maxi = dp[i];
                pos = i;
            }
        }
        List<Integer> ans = new ArrayList<>();
        while (pos != -1) {
            ans.add(nums[pos]);
            pos = hash[pos];
        }
        return ans;
    }
}