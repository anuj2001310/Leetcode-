/**
 * @param {number} n
 * @return {number}
 */
var maxProduct = function(num) {
    let n = 0;
    let m = 0;
    for (; num > 0; ) {
        let r = num % 10;
        if (r >= n) {
            m = n;
            n = r;
        }
        else if (r > m)
            m = r;
        num = Math.floor(num / 10);
    }
    return n * m;
};