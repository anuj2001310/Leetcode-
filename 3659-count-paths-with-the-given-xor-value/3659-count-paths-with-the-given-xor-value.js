/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var countPathsWithXorValue = function (grid, k) {
    const n = grid.length;
    const m = grid[0].length;

    var MOD = 1000000007;
    var MAX_XOR_VALUE = 16;

    const dp = Array.from({ length: n }, () =>
        Array.from({ length: m }, () =>
            Array(MAX_XOR_VALUE).fill(-1)
        )
    );

    const solve = (grid, i, j, val, k, dp) => {

        if (i === 0 && j === 0) {
            return (val ^ grid[0][0]) === k ? 1 : 0;
        }

        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j][val] !== -1) {
            return dp[i][j][val];
        }

        const up = solve(grid, i - 1, j, val ^ grid[i][j], k, dp);
        const left = solve(grid, i, j - 1, val ^ grid[i][j], k, dp);

        dp[i][j][val] = (up + left) % MOD;
        return dp[i][j][val];
    }
    const ans = solve(grid, n - 1, m - 1, 0, k, dp);

    return ans % MOD;
};