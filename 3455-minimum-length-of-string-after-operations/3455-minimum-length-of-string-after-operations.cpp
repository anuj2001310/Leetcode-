class Solution {
public:
    int minimumLength(string s) {
        uint n = s.length();
        vector<int> freq(26, 0);
        for (auto& ch : s)
            freq[ch - 'a']++;

        for (auto& ch : s)
            if (freq[ch - 'a'] > 2)
                freq[ch - 'a'] -= 2;

        int res = 0;
        for (auto& num : freq)
            res += num;
            
        return res;
    }
};