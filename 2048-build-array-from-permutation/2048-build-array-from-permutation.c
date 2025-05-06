/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int n, int* returnSize) {
    int* ans = (int*)calloc(sizeof(int), n);
    *returnSize = n;
    
    for (int i = 0; i < n; ++i)
        ans[i] = nums[nums[i]];
    
    free(nums);
    return ans;
}