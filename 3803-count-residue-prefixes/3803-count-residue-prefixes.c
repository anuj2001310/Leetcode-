int residuePrefixes(char* s) {
    int dis = 0, i = 0, ans = 0, n = strlen(s);
    int freq[26] = {};

    for (; *s; s++) {
        int ch = *s - 'a';
        if (freq[ch] == 0)
            dis++;
        freq[ch]++;
        ans += (dis == (i + 1) % 3);
        i++;
    }
    return ans;
}