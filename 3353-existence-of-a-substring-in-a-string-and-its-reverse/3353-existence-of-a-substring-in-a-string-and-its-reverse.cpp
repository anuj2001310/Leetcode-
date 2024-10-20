class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        for (int i = 0; i < n - 1; ++i) {
            string sub = s.substr(i, 2);
            if (t.find(sub) != string::npos)
                return true;
        }
        return false;
    }
};