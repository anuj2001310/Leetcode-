class Solution {
private:
    string change(string str) {
        string ch = "";
        for (int i = 0; i < str.length(); ++i) {
            int curr = str[i] - 'a';
            ch += (curr + '0');
        }
        return ch;
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string f, s, t;
        f = change(firstWord);
        s = change(secondWord);
        t = change(targetWord);
        return stoi(f) + stoi(s) == stoi(t);
    }
};