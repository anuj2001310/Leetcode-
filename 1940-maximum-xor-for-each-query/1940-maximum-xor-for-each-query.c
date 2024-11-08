/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize) {
    int* ans = (int*)calloc(sizeof(int), numsSize);
    int xor = 0;
    int b = (1 << maximumBit) - 1;

    for (int i = 0; i < numsSize; ++i)
        xor ^= nums[i];
    for (int i = 0; i < numsSize; ++i) {
        ans[i] = xor^b;
        xor ^= nums[numsSize - i - 1];
    }
    *returnSize = numsSize;
    return ans;
}