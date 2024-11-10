public class Solution {
    public int SmallestNumber(int n, int t) {
        for (; ; n++) {
            var num = n;
            var pro = 1;
            while (num != 0) {
                pro *= (num % 10);
                num /= 10;
            }
            if (pro % t == 0)
                return n;
        }
        return -1;
    }
}