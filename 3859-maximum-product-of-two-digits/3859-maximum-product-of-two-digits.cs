public class Solution {
    public int MaxProduct(int num) {
        var n = 0;
        var m = 0;
        for (; num > 0; ) {
            int r = num % 10;
            if (r >= n) {
                m = n;
                n = r;
            }
            else if (r > m)
                m = r;
            num /= 10;
        }
        return n * m;
    }
}