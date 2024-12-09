/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize,
                     int* queriesColSize, int* returnSize) {
    int* help = (int*)calloc(sizeof(int), numsSize);
    for (int i = 1; i < numsSize; ++i)
        help[i] = (nums[i] ^ nums[i - 1]) & 1 ? help[i - 1] : i;
    bool* ans = (bool*)calloc(sizeof(bool), queriesSize);

    *returnSize = 0;
    for (int i = 0; i < queriesSize; ++i) {
        int f = queries[i][0];
        int t = queries[i][1];
        ans[(*returnSize)++] = help[t] <= f;
    }
    return ans;
}