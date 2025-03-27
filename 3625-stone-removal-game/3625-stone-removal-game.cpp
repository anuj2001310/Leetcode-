class Solution {
public:
    bool canAliceWin(int n) {
        for (int i = 10; i >= 0; --i) {
            if (n < i)
                return i & 1;
            n -= i;
        }
        return false;
    }
};