class Solution {
    public int smallestNumber(int n, int t) {
        for (;; n++) {
            int num = n;
            int pro = 1;
            while (num != 0) {
                pro *= (num % 10);
                num /= 10;
            }
            if (pro % t == 0)
                return n;
        }
    }
}