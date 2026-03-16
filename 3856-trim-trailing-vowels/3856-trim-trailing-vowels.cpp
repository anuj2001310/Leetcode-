class Solution {
private:
    bool vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    string trimTrailingVowels(string s) {
        int n = s.length();
        int id = n - 1;
        while (id >= 0) {
            if (!vowel(s[id]))
                break;
            id--;
        }
        return s.substr(0, id + 1);
    }
};