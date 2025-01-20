/**
 * @param {number[]} arr
 * @param {number[][]} mat
 * @return {number}
 */
class Pair {
    constructor(first, second) {
        this.first = first;
        this.second = second;
    }
}
var firstCompleteIndex = function (arr, mat) {
    const n = mat.length;
    const m = mat[0].length;
    const temp = new Array(n * m + 1);

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            temp[mat[i][j]] = new Pair(i, j);
        }
    }

    const rows = new Array(n).fill(0);
    const cols = new Array(m).fill(0);

    for (let i = 0; i < n * m; ++i) {
        const r = temp[arr[i]].first;
        const c = temp[arr[i]].second;
        rows[r]++;
        cols[c]++;

        if (rows[r] === m || cols[c] === n) {
            return i;
        }
    }

    return -1;
};