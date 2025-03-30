/**
 * @param {string} s
 * @return {number[]}
 */
var partitionLabels = function(s) {
    let n = s.length;
    const ans = []
    const arr = new Array(26).fill(0);

    for (let i = 0; i < n; ++i) {
        let idx = s.charCodeAt(i) - 97;
        arr[idx] = i;
    }
    let prev = -1, last = -1;
    for (let i = 0; i < n; ++i) {
        let idx = s.charCodeAt(i) - 97;
        if (arr[idx] > last)
            last = arr[idx];
        if (i == last) {
            ans.push(i - prev);
            prev = i;
        }
    }
    return ans;
};