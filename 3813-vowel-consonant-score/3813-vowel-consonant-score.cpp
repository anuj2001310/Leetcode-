class Solution {

public:
    int vowelConsonantScore(string s) {
        auto isVowel = [&](char ch) -> bool {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                   ch == 'u';
        };

        auto isCon = [&](char ch) -> bool {
            if (ch >= 'a' and ch <= 'z' && !isVowel(ch))
                return true;
            return false;
        };
        int n = s.length();
        int v = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            if (isVowel(s[i]))
                v++;
            if (isCon(s[i]))
                c++;
        }
        int score = (c == 0 ? 0 : v / c);
        return score;
    }
};