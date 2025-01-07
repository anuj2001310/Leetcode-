/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int wordsSize, int* returnSize) {
    char** ans = (char**)malloc(sizeof(*words) * wordsSize);
    int t = 0;
    for (int i = 0; i < wordsSize; i++)
        for (int j = i + 1; j < wordsSize; j++)
            if (words[j] && words[i] &&
                (strstr(words[i], words[j]) || strstr(words[j], words[i]))) {
                if (strstr(words[i], words[j])) {
                    ans[t] = words[j];
                    t++;
                    words[j] = NULL;
                } else {
                    ans[t] = words[i];
                    t++;
                    words[i] = NULL;
                }
            }
    *returnSize = t;
    return ans;
}