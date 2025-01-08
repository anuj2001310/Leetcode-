/**
 * @param {string[]} words
 * @return {number}
 */
var countPrefixSuffixPairs = function(words) {
    var cnt = 0
    for (let i = 0; i < words.length; ++i)
        for (let j = i + 1; j < words.length; ++j)
            if (words.at(j).startsWith(words.at(i)) && words.at(j).endsWith(words.at(i)))
                cnt++
    return cnt
};