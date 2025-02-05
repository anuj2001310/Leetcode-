class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        vector<int> a(26, 0), b(26, 0);
        int cnt = 0;
        for (int i = 0; i < s1.length(); i++) {
            int idx1 = s1[i] - 'a';
            int idx2 = s2[i] - 'a';
            a[idx1]++;
            b[idx2]++;
            if (s1[i] != s2[i])
                cnt++;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return cnt <= 2;
    }
};