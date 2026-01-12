/**
 * @param {string} s
 * @return {number}
 */
var residuePrefixes = function(s) {
    let n = s.length;
    let dis = 0, ans = 0;
    let freq = new Array(26).fill(0);
    for (let i = 0; i < n; ++i) {
        let ch = s.charCodeAt(i) - 97;
        if (freq[ch] === 0)
            dis++;
        
        freq[ch]++;
        ans += (dis == ((i + 1) % 3));
    }
    return ans;
};