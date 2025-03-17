bool divideArray(int* nums, int numsSize) {
    int dict[501] = {};
    for (int u = 0; u < numsSize; u++)
        dict[nums[u]]++;
    for (int i = 0; i < 501; ++i)
        if (dict[i] & 1)
            return false;
    return true;
}