int minimumLength(char* s) {
    int freq[26] = {};
    for (int i = 0; s[i]; i++)
        freq[s[i] - 'a']++;

    int res = 0;
    for (; *s; s++) {
        if (freq[*s - 'a'] > 2)
            freq[*s - 'a'] -= 2;
    }
    for (int i = 0; i < 26; i++)
        res += freq[i];
    return res;
}