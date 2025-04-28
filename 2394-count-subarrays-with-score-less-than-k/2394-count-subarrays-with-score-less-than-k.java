class Solution {
    public long countSubarrays(int[] nums, long k) {
        long res = 0, cnt = 0, sum = 0;
        int n = nums.length, l = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            cnt++;
            while (sum * cnt >= k) {
                sum -= nums[l++];
                cnt--;
            }
            res += cnt;
        }
        return res;
    }
}