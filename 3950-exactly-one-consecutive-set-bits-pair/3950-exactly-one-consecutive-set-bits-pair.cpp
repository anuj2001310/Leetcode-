class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        int prev = -1;
        while (n) {
            int r = n % 2;
            if (r == prev && r)
                cnt++;
            if (cnt > 1)
                break;
            n >>= 1;
            prev = r;
        }
        return cnt == 1;
    }
};