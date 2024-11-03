/**
 * @param {string} num
 * @return {boolean}
 */
var isBalanced = function(num) {
    let sum = 0
    for (let i  = 0; i < num.length; ++i) {
        let dig = num.charCodeAt(i) - '48'
        if (i & 1)
            sum += dig
        else
            sum -= dig
    }
    return sum === 0
};