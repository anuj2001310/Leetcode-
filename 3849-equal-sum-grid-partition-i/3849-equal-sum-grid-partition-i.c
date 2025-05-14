typedef long long ll;

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = *gridColSize;
    ll* rowSum = (ll*)calloc(sizeof(ll), n);
    ll* colSum = (ll*)calloc(sizeof(ll), m);
    
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            tot += grid[i][j];
            rowSum[i] += grid[i][j];
            colSum[j] += grid[i][j];
        }
    }
    if (tot & 1)
        return false;

    ll pref = 0LL;
    for (int i = 0; i < n - 1; ++i) {
        pref += rowSum[i];
        if ((pref << 1) == tot) {
            free(rowSum);
            free(colSum);
            return true;
        }
    }
    
    pref = 0LL;
    for (int i = 0; i < m - 1; ++i) {
        pref += colSum[i];
        if ((pref << 1) == tot) {
            free(rowSum);
            free(colSum);
            return true;
        }
    }

    free(rowSum);
    free(colSum);
    return false;
}