class Solution {
public:
    int smallestNumber(int n, int t) {
        for (; n; ++n) {
            int num = n;
            int pro = 1;
            while (num) {
                pro *= (num % 10);
                num /= 10;
            }
            if (pro % t == 0)
                return n;
        }
        return -1;
    }
};