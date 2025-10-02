class Solution {
public:
    int maxBottlesDrunk(int a, int b) {
        int ans = 0;
        int x = 0;
        while (a) {
            ++ans, ++x, --a;
            if (x >= b) {
                x -= b;
                ++a;
                ++b;
            }
        }
        return ans;
    }
};