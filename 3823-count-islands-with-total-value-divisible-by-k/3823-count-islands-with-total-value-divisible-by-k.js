/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var countIslands = function (grid, k) {
    let n = grid.length;
    let m = grid[0].length;
    const vis = Array.from({length : n }, () => Array(m).fill(false));
    console.log(vis);
    
    const dfs = (r, c) => {
        if (r >= n || r < 0 || c >= m || c < 0 || vis[r][c] || grid[r][c] == 0)
            return 0;

        vis[r][c] = true;
        let sum = grid[r][c];
        sum += dfs(r - 1, c);
        sum += dfs(r, c + 1);
        sum += dfs(r + 1, c);
        sum += dfs(r, c - 1);

        return sum;
    }
    
    let cnt = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            if (!vis[i][j] && grid[i][j] > 0) {
                let val = dfs(i, j);
                if (val % k === 0) cnt++;
            }
        }
    }
    return cnt;
};
