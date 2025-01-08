class Solution {
private:
    bool func(string& w1, string& w2) {
        int n = w1.length(), m = w2.length();
        if (n > m)
            return false;
        bool flag = true;
        for (int l1 = 0, r1 = n - 1, l2 = 0, r2 = m - 1; l1 < n && r1 >= 0 && l2 < m && r2 >= 0 && flag; ++l1, --r1, ++l2, --r2)
            flag = (w1[l1] == w2[l2]) and (w1[r1] == w2[r2]);
        return flag;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int l = words.size();
        int ans = 0;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; ++j)
                ans += func(words[i], words[j]);
        }
        return ans;
    }
};