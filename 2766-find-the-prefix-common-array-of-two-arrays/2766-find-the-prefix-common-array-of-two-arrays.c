/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int n = ASize;
    int* ans = calloc(sizeof(int), n);
    bool* presentA = (bool*)calloc(sizeof(bool), n + 1);
    bool* presentB = (bool*)calloc(sizeof(bool), n + 1);
    int cnt = 0;
    *returnSize = 0;
    for (int i = 0; i < n; i++) {
        cnt += A[i] == B[i];
        cnt += presentA[B[i]];
        cnt += presentB[A[i]];
        presentA[A[i]] = true;
        presentB[B[i]] = true;
        ans[(*returnSize)++] = cnt;
    }
    return ans;
}