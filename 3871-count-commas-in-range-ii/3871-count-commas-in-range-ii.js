/**
 * @param {number} n
 * @return {number}
 */
var countCommas = function(n) {
    let ans = 0;
    let base = 1000;
    while (base <= n) {
        ans += (n - base + 1);
        base *= 1000;
    }
    return ans;
};