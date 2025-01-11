/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
var canConstruct = function(s, k) {
    let n = s.length;
    if (n < k)
        return false;
    const arr = Array(26).fill(0)
    for (let i = 0; i < n; i++)
        arr[s.charCodeAt(i) - 97]++;
    let cnt = 0;
    for (let i = 0; i < 26; i++) {
        if (arr[i] & 1)
            cnt++;
    }
    if (cnt > k)
        return false;

    return true;
};