class Solution {
public:
    int minimumDeletions(string s, int x) {
        int n = s.length();

        array<int, 26> freq;
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;

        int ans = std::numeric_limits<int>::max();

        for (int j = 0; j < 26; j++) {
            if (freq[j] == 0)
                continue;

            int del = 0;
            int a = freq[j];

            for (int k = 0; k < 26; ++k) {
                if (freq[k] == 0)
                    continue;
                int b = freq[k];
                if (a > b)
                    del += b;
                else if (abs(b - a) > x)
                    del += abs(b - (a + x));
            }

            ans = min({ans, del});
        }

        return ans;
    }
};