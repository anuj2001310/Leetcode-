/**
 * @param {number[]} arr
 * @return {boolean}
 */
var threeConsecutiveOdds = function(arr) {
    let n = arr.length, mask = (1 << 1);
    let cnt = 0;
    for (let i = 0; i < n; ++i) {
        if (arr[i] & 1)
            cnt++;
        else
            cnt = 0;
        if ((cnt & 1) && (mask & cnt))
            return true;
    }
    return false;
};