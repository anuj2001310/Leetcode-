class Solution {
public:
    int mirrorDistance(int n) {
        int y = n;
        int rn = 0;
        while (y) {
            rn = rn * 10 + y % 10;
            y /= 10;
        }
        return abs(n - rn);
    }
};