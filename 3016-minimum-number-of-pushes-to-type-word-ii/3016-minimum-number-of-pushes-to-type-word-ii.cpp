typedef vector<int> vi;
#define Rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    int minimumPushes(string word) {
        vi freq(26, 0);
        for (auto& nxt : word)
            freq[nxt - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        Rep(i, 26) {
            int cost = i / 8 + 1;
            ans += cost * freq[i];
        }
        return ans;
    }
};