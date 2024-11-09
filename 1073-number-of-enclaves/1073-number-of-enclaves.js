/**
 * @param {number[][]} grid
 * @return {number}
 */
var numEnclaves = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    let count = 0;

    function dfs(i, j) {
        if (i < 0 || i >= m || j < 0 || j >= grid[i].length || grid[i][j] === 0) return;

        grid[i][j] = 0;

        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1 && (i === 0 || j === 0 || i === m - 1 || j === n - 1))
                dfs(i, j);
        }
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                count++;
            }
        }
    }

    return count;
};