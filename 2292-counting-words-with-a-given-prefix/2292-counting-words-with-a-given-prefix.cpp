class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int cnt = 0;
        for (auto& str : words) {
            if (str.substr(0, pref.length()) == pref)
                cnt++;
        }
        return cnt;
    }
};