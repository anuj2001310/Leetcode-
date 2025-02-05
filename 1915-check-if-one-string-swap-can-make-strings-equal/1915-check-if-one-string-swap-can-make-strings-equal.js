/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var areAlmostEqual = function(s1, s2) {
    let n = s1.length;
    const a = new Array(26).fill(0);
    const b = new Array(26).fill(0);
    let cnt = 0;
    for (let i = 0; i < n; i++) {
        let idx1 = s1.charCodeAt(i) - 97;
        let idx2 = s2.charCodeAt(i) - 97;
        if (s1[i] != s2[i])
            cnt++;
        a[idx1]++;
        b[idx2]++;
    }
    for (let i = 0; i < 26; i++) {
        if (a[i] != b[i])
            return false;
    }
    return cnt <= 2;
};