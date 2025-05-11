int maxFreqSum(char* s) {
    int n = strlen(s);
    int* freq = (int*)calloc(sizeof(int), 26);
    int v = 0, c = 0;
    for (int i = 0; i < n; ++i)
        freq[s[i] - 'a']++;

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    for (; *s; s++) {
        int idx = *s - 'a';
        if (isVowel(*s))
            v = fmax(v, freq[idx]);
        else
            c = fmax(c, freq[idx]);
    }
    
    free(freq);
    return v + c;
}