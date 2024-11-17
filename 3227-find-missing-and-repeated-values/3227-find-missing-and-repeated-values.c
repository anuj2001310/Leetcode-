/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize,
                                  int* returnSize) {
    int* ans = (int*)calloc(sizeof(int), 2);
    *returnSize = 2;
    int reqSize = gridSize * gridSize + 1;
    int square[reqSize] = {};
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[i]; ++j)
            square[grid[i][j]]++;
    }
    for (int i = 0; i < reqSize; ++i) {
        if (square[i] == 2) {
            ans[0] = i;
        }
        if (square[i] == 0) {
            ans[1] = i;
        }
    }
    return ans;
}