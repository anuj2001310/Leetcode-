class Solution {
public:
    int maxDistance(string s, int k) {
        // N -> y++
        // S -> y--
        // E -> x++
        // W -> x--
        int x = 0, y = 0;
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            switch (ch) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            }
            ans = fmax(ans, min({abs(x) + abs(y) + k * 2, i + 1}));
        }
        return ans;
    }
};