/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)calloc(sizeof(int), 101);
    int min = INT_MAX;
    int max = INT_MIN;
    bool vis[101] = {};
    *returnSize = 0;
    for (int x = 0; x < numsSize; ++x) {
        min = fmin(min, nums[x]);
        max = fmax(max, nums[x]);
        vis[nums[x]] = true;
    }

    for (int i = min; i < max; ++i) {
        if (!vis[i])
            ans[(*returnSize)++] = i;
    }
    return ans;
}