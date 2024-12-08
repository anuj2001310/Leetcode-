class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n];

        for (int i = 0; i < n; ++i) {
            int j = i, v = nums[i];
            for (; v > 0; --v, j = (j + 1) % n);
            for (; v < 0; ++v, j = (j + n - 1) % n);
            arr[i] = nums[j];
        }

        return arr;
    }
}