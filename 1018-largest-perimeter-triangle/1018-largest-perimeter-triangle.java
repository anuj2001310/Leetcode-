class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int p = 0;
        for (int i = n - 1; i >= 2; i--) {
            int c = nums[i];
            int a = nums[i - 1];
            int b = nums[i - 2];

            if ((a + b) > c) {
                return a + b + c;
            }
        }

        return 0;
    }
}