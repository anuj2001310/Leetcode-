/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function (matrix) {
    var sum = 0;
    let cnt = 0, min = 1e5 + 1;
    for (let row of matrix) {
        for (let ele of row) {
            if (ele < 0)
                cnt++;
            sum += Math.abs(ele);
            min = Math.min(min, Math.abs(ele));
        }
    }
    if ((cnt & 1) != 0)
        return sum - 2 * Math.abs(min);

    return sum
};