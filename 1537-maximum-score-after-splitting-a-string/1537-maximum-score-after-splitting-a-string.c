int maxScore(char* s) {
    int o = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == '1')
            o++;
            
    int z = 0, ans = 0;
    int n = strlen(s);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1')
            o--;
        else
            z++;
        ans = fmax(ans, z + o);
    }
    return ans;
}