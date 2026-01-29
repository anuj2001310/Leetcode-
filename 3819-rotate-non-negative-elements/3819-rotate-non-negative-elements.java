class Solution {
    public int[] rotateElements(int[] nums, int k) {
        int n = nums.length, m = 0;
        int[] a = new int[n];

        for (int num : nums) {
            if (num >= 0)
                a[m++] = num;
        }
        if (m == 0)
            return nums;
        k %= m;
        for (int i = 0, j = 0; i < n; i++) {
            if (nums[i] >= 0)
                nums[i] = a[(j++ + k) % m];
        }
        return nums;
    }
}