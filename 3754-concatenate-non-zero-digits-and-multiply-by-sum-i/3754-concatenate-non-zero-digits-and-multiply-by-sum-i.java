class Solution {
    public long sumAndMultiply(int n) {
        long sum = 0;
        long ans = 0;
        for (; n > 0; ) {
            long r = n % 10;
            n /= 10;
            if (r == 0)
                continue;
            sum += r;
            ans = 10 * ans + r;
        }
        long res = 0;
        while (ans > 0) {
            res = res * 10 + ans % 10;
            ans /= 10;
        }
        return res * sum;
    }
}