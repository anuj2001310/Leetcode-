class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if (n < 3)
            return false;
        auto isVowel = [&](char ch) -> bool {
            return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or
                   ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or
                   ch == 'O' or ch == 'U';
        };
        auto isConsonent = [&](char ch) -> bool {
            if ((ch >= 'A' and ch <= 'Z') or (ch >= 'a' and ch <= 'z'))
                return !isVowel(ch);
            return false;
        };
        bool vowel = false, consonent = false;
        for (auto& ch : word) {
            if (ch == '@' or ch == '#' or ch == '$')
                return false;
            if (isVowel(ch))
                vowel = true;
            if (isConsonent(ch))
                consonent = true;
        }
        return vowel && consonent;
    }
};