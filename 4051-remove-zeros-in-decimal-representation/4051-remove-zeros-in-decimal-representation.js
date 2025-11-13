/**
 * @param {number} n
 * @return {number}
 */
var removeZeros = function (n) {
    let ans = 0;
    for (; n > 0;) {
        let r = n % 10;
        if (r != 0)
            ans = ans * 10 + r;
        n = Math.floor(n / 10);
    }

    while (ans !== 0) {
        n = n * 10 + ans % 10;
        ans = Math.floor(ans / 10);
    }
    return n;
};