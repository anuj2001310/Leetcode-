class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string temp = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (islower(ch)) {
                temp.push_back(ch);
                continue;
            }
            if (ch == '*' && !temp.empty())
                temp.pop_back();
            else if (ch == '#')
                temp += temp;
            else if (ch == '%')
                reverse(temp.begin(), temp.end());   
        }
        return temp;
    }
};