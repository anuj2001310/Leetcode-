/**
 * @param {string} s
 * @return {number}
 */
var maxScore = function (s) {
    let ones = 0;
    for (let ch of s)
        if (ch === '1')
            ones++;


    let ans = 0;
    let zeros = 0;
    for (let i = 0; i < s.length - 1; i++) {
        if (s[i] === '1') {
            ones--;
        } else {
            zeros++;
        }

        ans = Math.max(ans, zeros + ones);
    }

    return ans;
};