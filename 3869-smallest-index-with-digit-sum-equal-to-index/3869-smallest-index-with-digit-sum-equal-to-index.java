class Solution {
    public int smallestIndex(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int num = nums[i];
            while (num != 0) {
                sum += num % 10;
                if (sum > i)
                    break;
                num /= 10;
            }

            if (sum == i)
                return i;
        }
        return -1;
    }
}