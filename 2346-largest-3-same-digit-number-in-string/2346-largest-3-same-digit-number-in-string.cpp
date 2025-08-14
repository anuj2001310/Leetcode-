class Solution {
private:
    bool notUnique(string str) {
        int l = str.length();
        for (int i = 1; i < l; ++i) {
            if ((str[i] - '0') != (str[i - 1] - '0'))
                return false;
        }
        return true;
    }

public:
    string largestGoodInteger(string num) {
        int ans = 0;
        int n = num.length();
        string res = "";
        for (int i = 0; i < n - 2; ++i) {
            string t = num.substr(i, 3);
            bool flag = false;
            int val = t[0] - '0';
            int temp = val * 100 + val * 10 + val;
            if (notUnique(t))
                flag = true;
            if (flag and temp >= ans) {
                ans = fmax(ans, temp);
                res = t;
            }
        }

        return res;
    }
};