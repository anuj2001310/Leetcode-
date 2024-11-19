/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function(n) {
    var cnt = 0
    while (n) {
        cnt++
        n &= (n - 1)
    }
    return cnt
};