class Solution {
    public int sumOfDigits(int[] nums) {
        int min = Integer.MAX_VALUE;
        int n = nums.length;
        for (int i = 0; i < n; i++)
            min = Math.min(min, nums[i]);
        
        int sum = 0;
        while (min > 0) {
            sum += (min % 10);
            min /= 10;
        }
        return ((sum & 1) != 0) ? 0 : 1;
    }
}