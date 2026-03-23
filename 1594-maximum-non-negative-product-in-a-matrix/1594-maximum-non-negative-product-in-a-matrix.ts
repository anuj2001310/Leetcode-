function maxProductPath(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const MOD = 1e9 + 7;

    const dp = Array.from({ length: m }, () => new Array(n).fill(null));

    const dfs = (row, col) => {
        if (row === m - 1 && col === n - 1) return [grid[row][col], grid[row][col]];

        if (row >= m || col >= n) return [Infinity, -Infinity];

        if (dp[row][col] !== null) {
            return dp[row][col];
        }

        let [maxR, minR] = dfs(row, col + 1);
        let [maxD, minD] = dfs(row + 1, col);

        let minVal = Infinity;
        let maxVal = -Infinity;

        for (let val of [maxR, minR, maxD, minD]) {
            if (val == Infinity || val == -Infinity) continue;

            minVal = Math.min(minVal, grid[row][col] * val);
            maxVal = Math.max(maxVal, grid[row][col] * val);
        }

        return dp[row][col] = [minVal, maxVal];
    }

    const ans = dfs(0, 0);

    return ans[1] < 0 ? -1 : ans[1] % MOD;
};

/**
[
  -1, -4, 2
  4, 3, -1
  2 -4 4
  1 -1 -4
]
 */