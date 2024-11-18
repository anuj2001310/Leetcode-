/**
 * @param {number[]} chalk
 * @param {number} k
 * @return {number}
 */
var chalkReplacer = function (chalk, k) {
    let tot = 0
    chalk.forEach((x) => {
        tot += x
    })
    let re_after_rounds = k % tot
    for (let i = 0; i < chalk.length; ++i) {
        if (re_after_rounds < chalk[i])
            return i;
        re_after_rounds -= chalk[i]
    }
    return -1
};