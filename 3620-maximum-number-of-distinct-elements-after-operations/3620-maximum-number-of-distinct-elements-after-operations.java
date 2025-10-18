class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int cnt = 0;
        int pre = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            int curr = Math.min(Math.max(nums[i] - k, pre + 1), nums[i] + k);
            if (curr > pre) {
                cnt++;
                pre = curr;
            }
        }
        return cnt;
    }
}