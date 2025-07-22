class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int l = 0, r = 0;
        int temp = 0, max = 0;

        var map = new int[10001];
        for (; r < n; r++) {
            map[nums[r]]++;
            temp += nums[r];
            
            while (map[nums[r]] >= 2) {
                temp -= nums[l];
                map[nums[l++]]--;
            }

            max = Math.max(max, temp);
        }
        return max;
    }
}