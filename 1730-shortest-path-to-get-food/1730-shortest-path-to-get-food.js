/**
 * @param {character[][]} grid
 * @return {number}
 */
var getFood = function (grid) {
    const dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    let n = grid.length, m = grid[0].length;
    const q = []
    const vis = Array.from({ length: n }, () => Array(m).fill(false));

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            if (grid[i][j] === '*') {
                vis[i][j] = true;
                q.push([0, i, j])
            }
        }
    }

    //Main logic starts from here
    while (q.length > 0) {
        const [t, r, c] = q.shift();

        if (grid[r][c] === '#')
            return t;

        for (let dir of dirs) {
            let nr = r + dir[0];
            let nc = c + dir[1];

            if (
                nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                grid[nr][nc] !== 'X'
            ) {
                vis[nr][nc] = true;
                q.push([t + 1, nr, nc]);
            }
        }
    }
    return -1;
};