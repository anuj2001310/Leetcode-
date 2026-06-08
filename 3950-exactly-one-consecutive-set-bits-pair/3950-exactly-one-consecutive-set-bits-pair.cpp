class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        int p = -1;
        while (n) {
            int r = n % 2;
            if (r == p && r)
                cnt++;
            if (cnt > 1)
                break;
            n >>= 1;
            p = r;
        }
        return cnt == 1;
    }
};