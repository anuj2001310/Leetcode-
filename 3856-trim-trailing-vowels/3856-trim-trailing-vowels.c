bool v(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
char* trimTrailingVowels(char* s) {
    int n = strlen(s);
    int i = n - 1;
    while (i >= 0) {
        if (!v(s[i]))
            break;
        i--;
    }
    s[i + 1] = '\0';
    return s;
}