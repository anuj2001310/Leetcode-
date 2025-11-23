class Solution {
public:
    int minimumFlips(int n) {
        string s = "";
        for (; n;) {
            int r = n % 2;
            n /= 2;
            s += (r + '0');
        }
        int cnt = 0;
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s[l++] != s[r--])
                cnt++;
        }
        return 2 * cnt;
    }
};