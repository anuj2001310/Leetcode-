/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

 //DFS Solution in C
int dirs[][4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int r, int c, int** image, int** ans, int n, int m, int initial, int color) {
    ans[r][c] = color;
    for (int i = 0; i < 4; i++) {
        int nr = r + dirs[i][0];
        int nc = c + dirs[i][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            image[nr][nc] == initial && ans[nr][nc] != color)
            dfs(nr, nc, image, ans, n, m, initial, color);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int n = imageSize;
    int m = (*imageColSize);

    int initial = image[sr][sc];
    int** ans = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        ans[i] = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; ++j)
            ans[i][j] = image[i][j];
    }

    dfs(sr, sc, image, ans, n, m, initial, color);
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return ans;
}