public class Solution {
    public long RemoveZeros(long n) {
        long ans = 0;
        for (; n > 0; ) {
            long r = n % 10;
            if (r != 0)
                ans = ans * 10 + r;
            n /= 10;
        }

        while (ans != 0) {
            n = n * 10 + ans % 10;
            ans /= 10;
        }
        return n;
    }
}