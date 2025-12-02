class Solution {
public:
    int maxDistinct(string s) {
        array<int, 26> ans = {};
        int cnt = 0;
        for (auto& ch : s) {
            int idx = ch - 'a';
            if (ans[idx] == 0)
                cnt++;
            ans[idx]++;
        }
        return cnt;
    }
};