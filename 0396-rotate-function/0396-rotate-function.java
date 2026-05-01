class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        int sum = 0;
        int F = 0;
        // Step 1: Calculate the sum of all elements and the initial F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }
        int max = F;
        // Step 2: Calculate F(1) to F(n-1) using the recurrence relation
        // Apply formula: F(k) = F(k-1) + sum - n * last_element_of_prev_rotation
        for (int i = 1; i < n; i++) {
            F = F + sum - n * nums[n - i];
            // Update max if F is larger
            if (max < F) {
                max = F;
            }
        }
        return max;
    }
}