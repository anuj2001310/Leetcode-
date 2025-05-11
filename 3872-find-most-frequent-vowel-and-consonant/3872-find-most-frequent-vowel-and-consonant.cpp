class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (auto& ch : s)
            freq[ch - 'a']++;
        int vowel = 0, consonent = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i]))
                vowel = fmax(vowel, freq[s[i] - 'a']);
            else
                consonent = fmax(consonent, freq[s[i] - 'a']);
        }
        return vowel + consonent;
    }
};