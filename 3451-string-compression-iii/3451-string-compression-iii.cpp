class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;
        while(i < word.length()){
            int cnt = 1;
            char curr_char = word.at(i);
            while((i + 1) < word.length() and word[i + 1] == curr_char and cnt < 9){
                cnt += 1;
                i++;
            }
            comp += to_string(cnt) + curr_char;
            i++;
        }
        return comp;
    }
};