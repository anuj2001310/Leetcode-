/**
 * @param {number[][]} grid
 * @param {number[]} limits
 * @param {number} k
 * @return {number}
 */
var maxSum = function (grid, limits, k) {
    let list = []
    for (let row of grid)
        row.sort((a, b) => {
            return b - a;
        });
    for (let i = 0; i < limits.length; i++) {
        for (let j = 0; j < limits[i]; j++)
            list.push(grid[i][j]);
    }
    list.sort((a, b) => {
        return b - a;
    });

    let sum = 0;
    for (let i = 0; i < k; i++)
        sum += list[i];

    return sum;
};