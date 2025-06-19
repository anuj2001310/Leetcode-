class Solution {
    public int partitionArray(int[] nums, int k) {
        int n = nums.length;
        int cnt = 1;
        int min_val = Integer.MAX_VALUE, max_val = Integer.MIN_VALUE;
        Arrays.sort(nums);

        for (int i = 0; i < n; i++) {
            min_val = Math.min(min_val, nums[i]);
            max_val = Math.max(max_val, nums[i]);
            if (max_val - min_val > k) {
                cnt++;
                min_val = nums[i];
            }
        }
        return cnt;
    }
}