int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minDeletion(char* s, int k) {
    int* freq = (int*)calloc(26, sizeof(int));
    int distinct = 0;
    for (int i = 0; s[i]; i++)
        freq[s[i] - 'a']++;

    for (int i = 0; i < 26; ++i)
        if (freq[i])
            distinct++;
    if (k >= distinct)
        return 0;
    
    int del = 0;
    qsort(freq, 26, sizeof(int), cmp);
    for (int i = 0, j = 0; i < 26 && j < distinct  - k; i++) {
        if (freq[i]) {
            del += freq[i];
            j++;
        }
    }
    
    free(freq);
    return del;
}