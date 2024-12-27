/**
 * @param {number[]} values
 * @return {number}
 */
var maxScoreSightseeingPair = function (values) {
    let n = values.length;
    let ans = -214736548;
    let ind = 0;
    for (let i = 1; i < n; i++) {
        ans = Math.max(ans, values[ind] + values[i] - Math.abs(ind - i));
        if (values[i] + i > values[ind] + ind)
            ind = i;
    }
    return ans;
};