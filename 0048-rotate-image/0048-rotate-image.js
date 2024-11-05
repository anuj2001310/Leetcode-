/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    let n = matrix.length
    //Transpose of a matrix
    for (let i = 0; i < n; ++i) {
        for (let j = i; j < n; ++j) {
            let t = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = t
        }
    }

    //Reverse each row 
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < Math.floor(n / 2); ++j) {
            [matrix[i][j], matrix[i][n - j - 1]] = [matrix[i][n - j - 1], matrix[i][j]]
        }
    }
};