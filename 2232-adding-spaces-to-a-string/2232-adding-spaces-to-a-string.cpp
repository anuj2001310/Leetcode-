class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int i = 0, k = 0;
        while (i < s.length() && k < spaces.size()) {
            if (i == spaces[k]) {
                res += ' ';
                k++;
            }
            res += s[i];
            i++;
        }
        while (i < s.length())
            res += s[i++];
        return res;
    }
};