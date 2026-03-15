/**
 * @param {number} n
 * @return {number}
 */
var countCommas = function(n) {
    if (n < 999)
        return 0;
    
    return n - 999;
};