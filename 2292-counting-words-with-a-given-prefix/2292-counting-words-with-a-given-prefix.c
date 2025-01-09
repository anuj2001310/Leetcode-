int prefixCount(char** words, int wordsSize, char* pref) {
    int i, cnt = 0;
    int len = strlen(pref);
    for (i = 0; i < wordsSize; i++) {
        if (strncmp(words[i], pref, len) == 0)
            cnt++;
    }
    return cnt;
}