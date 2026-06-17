class Solution {
public:
    bool checkGoodInteger(int n) {
        int d = 0, s = 0;
        while (n) {
            int r = n % 10;
            n /= 10;
            if (r == 0)
                continue;
            d += r;
            s += (r * r);
        }
        return (s - d) >= 50;
    }
};