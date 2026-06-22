class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for (auto& ch : text)
            freq[ch - 'a']++;

        string s = "ballon";
        int ans = std::numeric_limits<int>::max();

        for (int i = 0; i < s.length(); ++i) {
            int id = s[i] - 'a';
            if (s[i] == 'l' || s[i] == 'o')
                ans = fmin(ans, freq[id] / 2);
            else
                ans = fmin(ans, freq[id]);
        }
        return ans;
    }
};