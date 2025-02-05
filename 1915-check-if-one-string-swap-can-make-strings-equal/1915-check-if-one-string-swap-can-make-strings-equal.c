bool areAlmostEqual(char* s1, char* s2) {
    int cnt = 0;
    int* a = (int*)calloc(sizeof(int), 26);
    int* b = (int*)calloc(sizeof(int), 26);

    for (int i = 0; s1[i]; ++i) {
        if (s1[i] != s2[i])
            cnt++;
        int id1 = s1[i] - 'a';
        int id2 = s2[i] - 'a';
        a[id1]++;
        b[id2]++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            free(a);
            free(b);
            return false;
        }
    }
    free(a);
    free(b);
    return cnt <= 2;
}