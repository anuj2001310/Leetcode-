/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function(n, t) {
    for (; ; ++n) {
        let num = n, pro = 1
        while (num) {
            pro *= (num % 10)
            num = Math.floor(num / 10)
        }
        if (pro % t == 0)
            return n
    }
    return -1
};