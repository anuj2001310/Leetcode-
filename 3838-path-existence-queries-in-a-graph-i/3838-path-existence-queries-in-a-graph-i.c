/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* comp = (int*)calloc(sizeof(int), n);
    int cnt = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] - nums[i - 1] <= maxDiff)
            comp[i] = cnt;
        else
            comp[i] = ++cnt;
    }

    bool* ans = (bool*)calloc(sizeof(bool), queriesSize);
    *returnSize = 0;
    
    for (int i = 0; i < queriesSize; ++i) {
        int u = queries[i][0];
        int v = queries[i][1];
        ans[(*returnSize)++] = (comp[u] == comp[v]);
    }
    
    free(comp);
    return ans;
}