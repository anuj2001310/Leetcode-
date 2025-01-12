/**
 * @param {number[][]} coins
 * @return {number}
 */
var maximumAmount = function (coins) {
    let m = coins.length, n = coins[0].length;
    let dp = Array.from({ length: m }).map(() => Array.from({ length: n }).map(() => new Array(3)));
    function dfs(i, j, x) {
        if (i == m - 1 && j == n - 1)
            return x > 0 ? Math.max(0, coins[i][j]) : coins[i][j];
        if (dp[i][j][x] != undefined)
            return dp[i][j][x];
        let next = -Infinity;
        if (i < m - 1)
            next = dfs(i + 1, j, x);
        if (j < n - 1)
            next = Math.max(next, dfs(i, j + 1, x));
        let res = coins[i][j] + next;
        if (coins[i][j] < 0 && x > 0) {
            next = -Infinity;
            if (i < n - 1)
                next = dfs(i + 1, j, x - 1);
            if (j < n - 1)
                next = Math.max(next, dfs(i, j + 1, x - 1));
            res = Math.max(res, next);
        }
        dp[i][j][x] = res;
        return res;
    }
    
    let res = dfs(0, 0, 2);
    return res;
};