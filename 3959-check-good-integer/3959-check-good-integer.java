class Solution {
    public boolean checkGoodInteger(int n) {
        int d = 0, s = 0;
        while (n != 0) {
            int r = n % 10;
            n /= 10;
            if (r == 0)
                continue;
            d += r;
            s += (r * r);
        }
        return s >= 50 + d;
    }
}