class Solution {
    public boolean canAliceWin(int n) {
        for (int i = 10; i >= 0; --i) {
            if (n < i)
                return (i & 1) != 0;
            n -= i;
        }
        return false;
    }
}