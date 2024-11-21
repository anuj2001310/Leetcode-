/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} guards
 * @param {number[][]} walls
 * @return {number}
 */
var countUnguarded = function (m, n, guards, walls) {
    const grid = Array.from({ length: m }, () => Array(n).fill(0));
    let freeCells = m * n - walls.length - guards.length;

    for (let [i, j] of walls) grid[i][j] = 'W';
    for (let [i, j] of guards) grid[i][j] = 'G';

    for (let [row, col] of guards) {
        for (let i = col + 1; i < n; i++) {
            if (grid[row][i] === 'W' || grid[row][i] === 'G') break;
            if (grid[row][i] === 0) {
                freeCells--;
                grid[row][i] = 'S';
            }
        }

        for (let i = col - 1; i >= 0; i--) {
            if (grid[row][i] === 'W' || grid[row][i] === 'G') break;
            if (grid[row][i] === 0) {
                freeCells--;
                grid[row][i] = 'S';
            }
        }

        for (let i = row + 1; i < m; i++) {
            if (grid[i][col] === 'W' || grid[i][col] === 'G') break;
            if (grid[i][col] === 0) {
                freeCells--;
                grid[i][col] = 'S';
            }
        }

        for (let i = row - 1; i >= 0; i--) {
            if (grid[i][col] === 'W' || grid[i][col] === 'G') break;
            if (grid[i][col] === 0) {
                freeCells--;
                grid[i][col] = 'S';
            }
        }
    }

    return freeCells;
};