public class Solution {
    public long CountSubarrays(int[] nums, int k) {
        long ans = 0;
        int m = 0;
        foreach (var num in nums)
            m = (num > m) ? num : m;

        int n = nums.Length, l = 0, r = 0, curr = 0;
        for (; r < n; ++r) {
            curr += (m == nums[r]) ? 1 : 0;
            while (curr >= k)
                curr -= (nums[l++] == m) ? 1 : 0;
            ans += l;
        }
        return ans;
    }
}