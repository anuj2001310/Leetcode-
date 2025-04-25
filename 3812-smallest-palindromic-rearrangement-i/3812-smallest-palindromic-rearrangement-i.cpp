class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if (n == 1)
            return s;
        vector<int> freq(26, 0);
        int min_idx = -1;
        for (auto& ch : s) {
            int idx = ch - 'a';
            freq[idx]++;
        }
        string first = "";
        for (int i = 0; i < 26; i++) {    
            first.append(freq[i] / 2, i + 'a');
            if (freq[i] & 1) {
                if (min_idx == -1)
                    min_idx = i;
            }
        }
        string last = first;
        reverse(last.begin(), last.end());

        if (min_idx == -1)
            return first + last;
        first += (min_idx + 'a');
        return first + last;
    }
};