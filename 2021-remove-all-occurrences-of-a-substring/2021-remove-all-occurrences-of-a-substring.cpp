class Solution {
private:
    bool checkMatch(stack<char> temp, string& part, int plen) {
        for (int i = plen - 1; i >= 0; i--) {
            if (temp.top() != part[i])
                return false;
            temp.pop();
        }
        return true;
    }
public:
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int n = s.length();
        int plen = part.length();

        for (int i = 0; i < n; i++) {
            stk.push(s[i]);

            if (stk.size() >= plen && checkMatch(stk, part, plen)) {
                for (int j = 0; j < plen; j++)
                    stk.pop();
            }
        }

        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }

        return res;
    }

};