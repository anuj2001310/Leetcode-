#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX_XOR_VALUE 16

int solve(int** grid, int i, int j, int val, int k, int*** dp, int n, int m) {

    if (i == 0 && j == 0)
        return (val ^ grid[0][0]) == k ? 1 : 0;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j][val] != -1) {
        return dp[i][j][val];
    }

    int up = solve(grid, i - 1, j, val ^ grid[i][j], k, dp, n, m);
    int left = solve(grid, i, j - 1, val ^ grid[i][j], k, dp, n, m);

    return dp[i][j][val] = (up + left) % MOD;
}
int countPathsWithXorValue(int** grid, int gridSize, int* gridColSize, int k) {
    int n = gridSize;
    int m = (*gridColSize);

    int*** dp = (int***)malloc(n * sizeof(int**));

    for (int i = 0; i < n; i++) {
        dp[i] = (int**)malloc(m * sizeof(int*));
        for (int j = 0; j < m; j++) {
            dp[i][j] = (int*)malloc(MAX_XOR_VALUE * sizeof(int));
            for (int l = 0; l < MAX_XOR_VALUE; l++)
                dp[i][j][l] = -1;
        }
    }

    int ans = solve(grid, n - 1, m - 1, 0, k, dp, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    // Return the result modulo MOD
    return ans % MOD;
}