bool isPrefixAndSuffix(char* str1, char* str2) {
    int n = strlen(str1), m = strlen(str2);
    for (int i = 0, j = 0; str1[i]; i++, j++)
        if (str1[i] != str2[j])
            return false;

    for (int i = n - 1, j = m - 1; j >= 0 && i >= 0; i--, j--)
        if (str1[i] != str2[j])
            return false;

    return true;
}

int countPrefixSuffixPairs(char** words, int wordsSize) {
    int cnt = 0;
    for (int i = 0; i < wordsSize; i++)
        for (int j = i + 1; j < wordsSize; j++)
            if (isPrefixAndSuffix(words[i], words[j]))
                cnt++;
    return cnt;
}