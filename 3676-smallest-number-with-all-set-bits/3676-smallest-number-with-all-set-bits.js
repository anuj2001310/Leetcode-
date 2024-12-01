/**
 * @param {number} n
 * @return {number}
 */
var smallestNumber = function(n) {
    while (n & (n + 1))
        n |= (n >> 1);
    
    return n;
};