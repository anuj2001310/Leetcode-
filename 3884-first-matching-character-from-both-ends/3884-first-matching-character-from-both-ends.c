int firstMatchingIndex(char* s) {
    int n = strlen(s);
    int i = 0;
    for (; 2 * i < n; i++) {
        if (s[i] == s[n - i - 1])
            return i;
    }
    return -1;
}