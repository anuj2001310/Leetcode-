class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (abs(s[i] - s[i - 1]) > 2)
                return false;
        }
        return true;
    }
};