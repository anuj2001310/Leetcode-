/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
    let c = 0, m = -1;
    let n = arr.length;
    for (let i = 0; i < n; i++) {
        m = Math.max (m, arr[i]);
        if (m == i)
            c++;
    }
    return c;
};