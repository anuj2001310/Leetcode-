class Solution {
    private boolean allSet(int num) {
        while (num != 0) {
            if ((num & 1) == 0)
                return false;
            num >>= 1;
        }
        return true;
    }
    public int smallestNumber(int n) {
        while (true) {
            if (allSet(n))
                return n;
            n++;
        }
    }
}