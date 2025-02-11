/**
 * @param {string} s
 * @param {string} part
 * @return {string}
 */
var removeOccurrences = function (s, part) {
    let currentStr = s;
    while (currentStr.includes(part)) {
        currentStr = currentStr.replace(part, '');
    }
    return currentStr;
};