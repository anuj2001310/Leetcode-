public class Solution {
    public long CountCommas(long n) {
        long ans = 0;
        long b = 1000;

        while (b <= n) {
            ans += (n - b + 1);
            b *= 1000;
        }

        return ans;
    }
}