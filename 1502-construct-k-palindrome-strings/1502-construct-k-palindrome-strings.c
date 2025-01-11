bool canConstruct(char* s, int k) {
    int n = strlen(s);
    if (n < k)
        return false;
    int freq[26] = {};
    for (; *s; s++)
        freq[*s - 'a']++;
    
    uint c = 0;
    for (uint i = 0; i < 26; i++) {
        if (freq[i] & 1)
            c++;
    }
    if (c > k)
        return false;
    
    return true;
}