class Solution {
    public int maximumPossibleSize(int[] nums) {
        int n = nums.length, cnt = 1;
        int num = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] >= num) {
                cnt++;
                num = nums[i];
            }
        }
        return cnt;
    }
}