class Solution {
    public long countSubarrays(int[] nums, int k) {
        long ans = 0;
        int n = nums.length, curr = 0;
        int l = 0, r = 0;
        int max = 0;
        for (int x : nums)
            max = (x > max ? x : max);
        for (; r < n; r++) {
            curr += (nums[r] == max) ? 1 : 0;
            while (curr >= k)
                curr -= (nums[l++] == max) ? 1 : 0;
            ans += l;
        }
        return ans;
    }
}