class Solution {
public:
    string compressedString(string word) {
        int i = 0;
        string comp = "";
        while (i < word.length()) {
            int cnt = 1;
            char curr = word[i];
            while (word[i + 1] == curr and (i + 1) < word.length() and
                   cnt < 9) {
                cnt++;
                i++;
            }
            comp += to_string(cnt) + curr;
            i++;
        }
        return comp;
    }
};