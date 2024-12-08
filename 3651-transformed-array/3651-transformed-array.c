/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructTransformedArray(int* nums, int n, int* returnSize) {
    int* res = (int*)calloc(sizeof(int), n);
    *returnSize = 0;
    for (int i = 0; i < n; i++) {
        int idx = (i + nums[i] % n + n) % n;
        res[(*returnSize)++] = nums[idx];
    }
    return res;
}