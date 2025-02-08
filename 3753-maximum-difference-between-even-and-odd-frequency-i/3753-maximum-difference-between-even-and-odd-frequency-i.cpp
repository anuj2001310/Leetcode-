class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq (26, 0);
        for (int i = 0; s[i]; ++i)
            freq[s[i] - 'a']++;
        int odd = INT_MIN, even = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                if (freq[i] & 1)
                    odd = fmax(odd, freq[i]);
                else
                    even = fmin(even, freq[i]);
            }
        }
        return odd - even;
    }
};