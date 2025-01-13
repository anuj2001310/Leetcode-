/**
 * @param {string} s
 * @return {number}
 */
var minimumLength = function (s) {
    const freq = Array(26).fill(0)
    let n = s.length;
    for (let i = 0; i < n; i++)
        freq[s.charCodeAt(i) - 97]++;

    let res = 0;
    for (let i = 0; i < n; i++) {
        let idx = s.charCodeAt(i) - 97;
        if (freq[idx] > 2)
            freq[idx] -= 2;
    }
    freq.forEach(x => {
        res += x;
    });
    return res;
};