class Solution {
public:
    string makeFancyString(string s) {
        string st = "";
        for (int i = 0; i < s.length(); ++i) {
            int k = 0;
            st += s[i];
            while (i + 1 < s.length() and s[i] == s[i + 1]) {
                if (k == 0)
                    st += s[i];
                i++;
                k++;
            }
        }
        return st;
    }
};