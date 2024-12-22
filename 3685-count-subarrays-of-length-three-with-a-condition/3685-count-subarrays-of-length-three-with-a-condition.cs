public class Solution {
    public int CountSubarrays(int[] nums) {
        int cnt = 0;
        int n = nums.Length;
        for (int i = 1; i < n - 1; ++i)
            cnt += (2 * (nums[i - 1] + nums[i + 1]) == nums[i]) ? 1 : 0;
        
        return cnt;
    }
}