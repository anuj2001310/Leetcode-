class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        int freq[26] = {};
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            freq[idx]++;
        }
        sort(freq, freq + 26);
        int cnt = 0;
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            if (freq[i] >= freq[i + 1]) {
                int prev = freq[i];
                freq[i] = fmax(0, freq[i + 1] - 1);
                cnt += (prev - freq[i]);
            }
        }
        return cnt;
    }
};