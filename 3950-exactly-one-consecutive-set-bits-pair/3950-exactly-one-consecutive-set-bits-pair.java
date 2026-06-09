class Solution {
    public boolean consecutiveSetBits(int n) {
        int cnt = 0;
        int p = -1;
        while (n != 0) {
            int r = n % 2;
            if (r == 1 && r == p)
                cnt++;
            n >>= 1;
            p = r;
        }
        return cnt == 1;
    }
}