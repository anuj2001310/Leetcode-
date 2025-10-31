class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int n = nums.length;
        int[] hash = new int[102];
        int[] ans = new int[2];
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            hash[nums[i]]++;
            if (hash[nums[i]] == 2)
                ans[idx++] = nums[i];
        }
        return ans;
    }
}