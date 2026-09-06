class Solution {
    public int sumDecoded(long[] nums) {
        long ans = 0;
        long MOD = 1000000007;
        for (int i = 0; i < nums.length; i++)
            ans = (ans + getAns(nums[i])) % MOD;

        return (int) ans;
    }

    private long getAns(long num) {
        long width = num % 10;
        long depth = num / 10;
        return XiYi(depth, width);
    }

    private long XiYi(long depth, long width) {
        long lenOfDepth = count(depth);
        long remaining = lenOfDepth - width;
        long divisor = power(10, remaining);
        long xi = depth / divisor;
        long yi = depth % divisor;

        return modPower(xi, yi);
    }

    private long count(long num) {
        long ct = 0;
        while (num > 0) {
            ct++;
            num /= 10;
        }

        return ct;
    }

    private long power(long base, long raise) {
        long prod = 1;
        while (raise > 0) {
            prod *= base;
            raise--;
        }

        return prod;
    }
    private long modPower(long base, long exp) {
        long MOD = 1000000007;
        long result = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
}