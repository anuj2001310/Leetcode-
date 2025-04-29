class Solution {
    public long countSubarrays(int[] nums, int k) {
        int max_ele = -1;
        for (int i = 0; i < nums.length; ++i)
            max_ele = nums[i] > max_ele ? nums[i] : max_ele;
        long ans = 0;
        int curr = 0, l = 0, r = 0;
        for (; r < nums.length; ++r) {
            curr += nums[r] == max_ele ? 1 : 0;
            while (curr >= k)
                curr -= nums[l++] == max_ele ? 1 : 0;
            ans += l;
        }
        return ans;
    }
}