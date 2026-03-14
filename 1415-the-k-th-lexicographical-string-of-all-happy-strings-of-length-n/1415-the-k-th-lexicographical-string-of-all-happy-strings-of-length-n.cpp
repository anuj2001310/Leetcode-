class Solution {
public:
    string ans = "";
    vector<char> v{'a', 'b', 'c'};
    bool f(int ind, string& s, int& k) {
        if (ind == s.size()) {
            k--;
            if (k == 0) {
                ans = s;
                return true;
            }
            return false;
        }
        for (auto& ch : v) {
            if (ind == 0 || (ind - 1 >= 0 && s[ind - 1] != ch)) {
                s[ind] = ch;
                bool dd = f(ind + 1, s, k);
                if (dd)
                    return true;
                s[ind] = '.';
            }
        }
        return false;
    }

    string getHappyString(int n, int k) {
        string s(n, '.');
        // cout<<s<<endl;
        f(0, s, k);
        return ans;
    }
};