int minChanges(char* s) {
    int cnt = 0;
    for (int i = 0; s[i]; i += 2) {
        if (s[i] != s[i + 1])
            cnt++;
    }
    return cnt;
}