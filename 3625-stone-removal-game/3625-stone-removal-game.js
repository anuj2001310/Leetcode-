/**
 * @param {number} n
 * @return {boolean}
 */
var canAliceWin = function(n) {
    for (let i = 10; i >= 0; i--) {
        if (n < i)
            return i & 1 != 0;
        n -= i;
    }
    return false;
};