/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function (grid) {
    let m = grid.length;
    let n = grid[0].length;
    let x = n + m;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                continue;
            }
            let top = x;
            let left = x;
            if (i - 1 >= 0) top = grid[i - 1][j];
            if (j - 1 >= 0) left = grid[i][j - 1];
            grid[i][j] = Math.min(top, left) + 1;
        }
    }

    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            if (grid[i][j] === 1) {
                continue;
            }
            let bottom = x;
            let right = x;
            if (i + 1 < m) bottom = grid[i + 1][j];
            if (j + 1 < n) right = grid[i][j + 1];
            grid[i][j] = Math.min(grid[i][j], Math.min(bottom, right) + 1);
        }
    }

    let count = Number.MIN_SAFE_INTEGER;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            count = Math.max(count, grid[i][j]);
        }
    }
    return count - 1 === n + m + 1 || count - 1 === 0 ? -1 : count - 1;
};