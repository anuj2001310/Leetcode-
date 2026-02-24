/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* toggleLightBulbs(int* bulbs, int n, int* returnSize) {
    *returnSize = 0;
    bool map[101] = {};
    for (int i = 0; i < n; ++i) {
        if (map[bulbs[i]])
            map[bulbs[i]] = false;
        else
            map[bulbs[i]] = true;
    }
    int* ans = (int*)calloc(sizeof(int), 101);
    for (int i = 0; i < 101; ++i) {
        if (map[i])
            ans[(*returnSize)++] = i;
    }
    return ans;
}