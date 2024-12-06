class Solution {
    public int repeatedNTimes(int[] nums) {
        int num_l = nums.length;
        int n = (num_l >> 1);
        int[] hash = new int[10001];
        for (int i = 0; i < num_l; ++i) {
            hash[nums[i]]++;
            if (hash[nums[i]] >= n)
                return nums[i];
        }
        return -1;
    }
}