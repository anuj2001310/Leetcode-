/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* zigzagTraversal(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int area = gridSize * (*gridColSize);
    int* ans = (int*)malloc((area + 1) / 2 * sizeof(int));
    *returnSize = (area + 1) / 2;
    int pt = 0;
    for (int i = 0; i < gridSize; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < *gridColSize; j++) {
                if ((pt & 1) == 0)
                    ans[pt / 2] = grid[i][j];
            
                pt++;
            }
        } else {
            for (int j = *gridColSize - 1; j >= 0; j--) {
                if ((pt & 1) == 0) 
                    ans[pt / 2] = grid[i][j];

                pt++;
            }
        }
    }
    return ans;
}