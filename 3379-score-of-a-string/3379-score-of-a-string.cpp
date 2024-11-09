class Solution {
public:
    int scoreOfString(string s) {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        int sum = 0;
        for (int i = s.length() - 1; i > 0; --i)
            sum += fabs(s[i] - s[i - 1]);
        return sum;
    }
};