/**
 * @param {number[][]} grid
 * @return {number}
 */
var closedIsland = function (grid) {
    let m = grid.length, n = grid[0].length;
    let closed = true;
    const dfs = function (r, c) {
        if (r < 0 || r == m || c < 0 || c == n) {
            return 0;
        }
        if (grid[r][c]) {
            return grid[r][c];
        }
        grid[r][c] = 1;
        let allDirs = dfs(r, c + 1) + dfs(r, c - 1) + dfs(r - 1, c) + dfs(r + 1, c);
        if (allDirs < 4) {
            closed = false;
        }
        return grid[r][c];
    }

    let ans = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                closed = true;
                dfs(i, j);
                if (closed) {
                    ans++;
                }
            }
        }
    }

    return ans;
};