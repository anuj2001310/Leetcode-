/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var zigzagTraversal = function (grid) {
    const ans = []

    let n = grid.length, m = grid[0].length;

    let skip = false
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            let jj = j;
            if (i % 2 == 1) {
                jj = m - 1 - j
            }
            if (!skip)
                ans.push(grid[i][jj])

            skip = !skip
        }
    }

    return ans
};