/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function (grid) {
    const dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]

    let res = 0
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (grid[i][j] === 1) {
                q = [[i, j]]
                let curMax = 0
                while (q.length > 0) {
                    const [r, c] = q.shift()
                    if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] !== 1) 
                        continue
                    grid[r][c] = 2
                    curMax++
                    for (const d of dir) {
                        let i = r + d[0]
                        let j = c + d[1]
                        q.push([i, j])
                    }

                }
                res = Math.max(curMax, res)
            }
        }
    }

    return res
};