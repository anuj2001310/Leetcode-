/**
 * @param {number[][]} isWater
 * @return {number[][]}
 */
var highestPeak = function (isWater) {
    const n = isWater.length
    const m = isWater[0].length
    const grid = Array.from({ length: n }, () => Array(m).fill(-1))
    const dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    let queue = []

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (isWater[i][j] === 1) {
                grid[i][j] = 0
                queue.push([i, j])
            }
        }
    }

    while (queue.length) {
        const newQueue = []
        for (let [i, j] of queue) {
            for (const [dx, dy] of dirs) {
                const x = i + dx
                const y = j + dy

                if (x < 0 || x >= n || y < 0 || y >= m) continue
                if (grid[x][y] !== -1) continue

                grid[x][y] = grid[i][j] + 1
                newQueue.push([x, y])
            }
        }

        queue = newQueue
    }


    return grid
};