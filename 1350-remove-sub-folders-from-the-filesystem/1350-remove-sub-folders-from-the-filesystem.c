/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
    qsort(folder, folderSize, sizeof(char*), compare);

    char** result = malloc(sizeof(char*) * folderSize);
    int currentLen = strlen(folder[0]);
    result[0] = folder[0];
    *returnSize = 1;
    for (int i = 1; i < folderSize; i++) {
        int newLen = strlen(folder[i]);
        if (newLen <= currentLen || folder[i][currentLen] != '/' ||
            strncmp(result[*returnSize - 1], folder[i], currentLen) != 0) {
            currentLen = newLen;
            result[*returnSize] = folder[i];
            (*returnSize)++;
        }
    }

    return result;
}