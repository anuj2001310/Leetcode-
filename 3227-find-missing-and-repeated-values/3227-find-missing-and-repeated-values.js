/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findMissingAndRepeatedValues = function(grid) {
    let n = grid.length
    const square = Array(n * n + 1).fill(0)
    for (let i = 0; i < grid.length; ++i) {
        for (let j = 0; j < grid[i].length; ++j)
            square[grid[i][j]]++
    }
    const arr = Array(2).fill(0);
    for (let i = 0; i < square.length; ++i) {
        if (square[i] === 2)
            arr[0] = i
        if (square[i] === 0)
            arr[1] = i
    }
    return arr
};