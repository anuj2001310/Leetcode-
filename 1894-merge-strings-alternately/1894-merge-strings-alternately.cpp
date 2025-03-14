class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int i = 0, j = 0;
        int n = w1.length(), m = w2.length();
        string ans = "";
        while (i < n && j < m) {
            ans = ans + w1[i] + w2[j];
            i++;
            j++;
        }
        while (i < n)
            ans += w1[i++];
        while (j < m)
            ans += w2[j++];
        return ans;
    }
};