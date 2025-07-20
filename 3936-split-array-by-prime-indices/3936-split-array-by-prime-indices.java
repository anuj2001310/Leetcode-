class Solution {
    private boolean isPrime (int num) {
        if (num <= 1)
            return false;
        
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0)
                return false;
        }
        
        return true;
    }
    public long splitArray(int[] nums) {
        int n = nums.length;
        long sumA = 0, sumB = 0;
        
        for (int i = 0; i < n; ++i) {
            if (isPrime(i))
                sumA += nums[i];
            else
                sumB += nums[i];
        }
        return Math.abs(sumA - sumB);
    }
}