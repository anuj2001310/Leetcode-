/**
 * @param {number[][]} grid
 * @return {number}
 */
var countServers = function (grid) {
    const n = grid.length;
    const m = grid[0].length;

    let ans = 0;
    let row = new Array(m).fill(0);
    let l = new Array(n).fill(-1);

    for (let r = 0; r < n; r++) {
        let s = 0;
        for (let c = 0; c < m; c++) {
            if (grid[r][c] === 1) {
                s++;
                row[c]++;
                l[r] = c;
            }
        }

        if (s !== 1) {
            ans += s;
            l[r] = -1;
        }
    }

    for (let r = 0; r < n; r++) {
        if (l[r] !== -1 && row[l[r]] > 1) {
            ans++;
        }
    }

    return ans;
};
