/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var minDeletion = function(s, k) {
    const freq = Array(26).fill(0);
    let dis = 0;

    for (let i = 0; i < s.length; i++) {
        let idx = s.charCodeAt(i) - 97;
        if (freq[idx] == 0)
            dis++;
        freq[idx]++;
    }

    if (k >= dis)
        return 0;

    freq.sort((a, b) => {
        return a - b;
    });

    let del = 0;
    for (let i = 0, j = 0; i < 26 && j < dis - k; i++) {
        if (freq[i] != 0) {
            del += freq[i];
            j++;
        }
    }
    return del;
    
};