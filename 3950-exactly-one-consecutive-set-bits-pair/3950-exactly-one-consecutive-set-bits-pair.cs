public class Solution {
    public bool ConsecutiveSetBits(int n) {
        int c = 0, p = -1;
        for (; n > 0; n >>= 1) {
            int r = ((n & 1) != 0) ? 1 : 0;
            if (r == 1 && r == p)
                c++;
            p = r;
        }
        return c == 1;
    }
}