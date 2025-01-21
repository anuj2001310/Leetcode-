typedef long long ll;
long long gridGame(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int m = (*gridColSize);
    long long top_sum = 0;
    long long res = LLONG_MAX;
    for (int i = 0; i < m; i++)
        top_sum += grid[0][i];
    long long bottom_sum = 0;

    for (int i = 0; i < m; ++i) {
        top_sum -= grid[0][i];
        res = fmin(res, fmax(top_sum, bottom_sum));
        bottom_sum += grid[1][i];
    }

    return res;
}