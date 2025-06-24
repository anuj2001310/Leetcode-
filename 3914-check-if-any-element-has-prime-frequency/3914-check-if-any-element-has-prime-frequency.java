class Solution {
    private boolean isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    public boolean checkPrimeFrequency(int[] nums) {
        int n = nums.length;
        var map = new int[101];
        for (int i = 0; i < n; i++)
            map[nums[i]]++;

        for (int i = 0; i < 101; i++) {
            if (map[i] == 0)
                continue;
            if (isPrime(map[i]))
                return true;
        }
        return false;
    }
}