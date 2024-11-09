/**
 * @param {number[][]} grid
 * @return {number}
 */
var numEnclaves = function (grid) {
    let maxCol = grid[0].length;
    let maxRow = grid.length;
    let rowMov = [0, 0, 1, -1];
    let colMov = [1, -1, 0, 0];
    function bfs(x, y) {

        function getNei(r, c) {
            let res = [];
            for (let i = 0; i < 4; i++) {
                let n_r = r + rowMov[i];
                let n_c = c + colMov[i];

                if (n_r >= 0 && n_c >= 0 && n_r < maxRow && n_c < maxCol && grid[n_r][n_c] === 1) {
                    res.push([n_r, n_c]);
                }
            }
            return res;
        }

        let q = [[x, y]];
        while (q.length) {
            let [c_x, c_y] = q.shift();
            for (let [nei_x, nei_y] of getNei(c_x, c_y)) {
                grid[nei_x][nei_y] = 2;
                q.push([nei_x, nei_y]);
            }
        }
    }

    for (let row = 0; row < grid.length; row++) {
        if (grid[row][0] === 1) {
            grid[row][0] = 2;
            bfs(row, 0);
        }
        if (grid[row][maxCol - 1] === 1) {
            grid[row][maxCol - 1] = 2;
            bfs(row, maxCol - 1)
        }
    }

    for (let col = 0; col < maxCol; col++) {
        if (grid[0][col] === 1) {
            grid[0][col] = 2;
            bfs(0, col)
        }
        if (grid[maxRow - 1][col] === 1) {
            grid[maxRow - 1][col] = 2;
            bfs(maxRow - 1, col);
        }
    }

    let res = 0;
    for (let row = 0; row < grid.length; row++) {
        for (let col = 0; col < grid[0].length; col++) {
            if (grid[row][col] === 1) {
                res++
            }
        }
    }
    return res;
};