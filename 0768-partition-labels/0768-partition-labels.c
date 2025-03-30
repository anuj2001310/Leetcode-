/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int n = strlen(s);
    *returnSize = 0;

    int* ans = (int*)calloc(sizeof(int), 501);
    int arr[26] = {};

    for (int i = 0; i < n; ++i) {
        int idx = s[i] - 'a';
        arr[idx] = i;
    }
    int p = -1, l = -1;
    for (int i = 0; i < n; ++i) {
        int idx = s[i] - 'a';
        if (arr[idx] > l)
            l = arr[idx];
        if (i == l) {
            ans[(*returnSize)++] = (i - p);
            p = i;
        }
    }
    return ans;
}