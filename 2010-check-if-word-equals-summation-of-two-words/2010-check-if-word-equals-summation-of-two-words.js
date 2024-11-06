/**
 * @param {string} firstWord
 * @param {string} secondWord
 * @param {string} targetWord
 * @return {boolean}
 */
var isSumEqual = function(firstWord, secondWord, targetWord) {
    const v = (str) => {
        let val = 0
        for (let i = 0; i < str.length; ++i)
            val = val * 10 + (str.charCodeAt(i) - 97)
        return val
    }
    return v(firstWord) + v(secondWord) === v(targetWord)
};