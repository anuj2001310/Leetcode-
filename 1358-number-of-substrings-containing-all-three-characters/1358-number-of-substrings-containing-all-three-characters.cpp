class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = s.size();
        vector<int> last(3, -1);
        int ans = 0;
        for (int i = 0; i < l; i++) {
            last[s[i] - 'a'] = i;
            ans += (1 + min({last[0], last[1], last[2]}));
        }
        return ans;
    }
};