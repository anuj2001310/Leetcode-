public class Solution {
    public long SplitArray(int[] nums) {
        bool isPrime(int num) {
            if (num <= 1)
                return false;
            for (int i = 2; i <= Math.Sqrt(num); ++i) {
                if (num % i == 0)
                    return false;
            }
            return true;
        }
        
        int n = nums.Length;
        long sumA = 0, sumB = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(i))
                sumA += nums[i];
            else
                sumB += nums[i];
        }
        return Math.Abs(sumA - sumB);
    }
}