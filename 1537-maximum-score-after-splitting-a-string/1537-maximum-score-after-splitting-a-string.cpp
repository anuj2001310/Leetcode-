class Solution {
private:
    int check(int i, string s) {
        int zero = 0, ones = 0;
        for (int j = 0; j < i; j++) {
            if (s[j] == '0')
                zero++;
        }
        for (int j = i; j < s.size(); j++) {
            if (s[j] == '1')
                ones++;
        }
        return ones + zero;
    }

public:
    int maxScore(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++)
            ans = fmax(ans, check(i, s));
        return ans;
    }
};