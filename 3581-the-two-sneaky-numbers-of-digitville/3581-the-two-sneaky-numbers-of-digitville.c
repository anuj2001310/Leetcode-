/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)calloc(sizeof(nums), 2);
    *returnSize = 0;
    int hash[102] = {};
    for (int u = 0; u < numsSize; ++u) {
        if (++hash[nums[u]] == 2)
            ans[(*returnSize)++] = nums[u];
    }
    return ans;
}