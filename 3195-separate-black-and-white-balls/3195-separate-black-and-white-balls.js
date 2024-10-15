/**
 * @param {string} s
 * @return {number}
 */
var minimumSteps = function (s) {
    let res = 0, swaps = 0
    for (let ch of s) {
        if (ch === "1")
            swaps++
        else
            res += swaps
    }
    return res
};