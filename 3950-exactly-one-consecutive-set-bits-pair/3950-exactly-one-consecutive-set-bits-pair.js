/**
 * @param {number} n
 * @return {boolean}
 */
var consecutiveSetBits = function(n) {
    let cnt = 0, p = -1;
    while (n != 0) {
        let r = n % 2;
        if (r === 1 && r === p)
            cnt++;
        
        n >>= 1;
        p = r;
    }
    return cnt === 1;
};