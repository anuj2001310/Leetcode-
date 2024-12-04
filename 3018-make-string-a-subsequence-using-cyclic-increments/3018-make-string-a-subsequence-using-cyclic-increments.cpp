class Solution {
    inline char next(char& c) {
        if (c == 'z')
            return 'a';
        else
            return c + 1;
    }

public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str1.size() < str2.size())
            return false;
        int i = 0, size = str2.size();
        for (char& c : str1) {
            if (c == str2[i] or next(c) == str2[i])
                i++;
            if (i == size)
                return true;
        }
        return false;
    }
};