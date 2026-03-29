/**
 * @param {string} s
 * @return {number}
 */
var firstMatchingIndex = function(s) {
    let n = s.length;
    for (let u = 0; 2 * u < n; ++u) {
        if (s[u] === s[n - u - 1])
            return u;
    }
    return -1;
};