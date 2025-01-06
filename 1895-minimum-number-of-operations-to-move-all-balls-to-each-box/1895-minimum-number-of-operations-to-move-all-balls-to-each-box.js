/**
 * @param {string} boxes
 * @return {number[]}
 */
var minOperations = function (boxes) {
    let n = boxes.length;
    let b = 0, m = 0;
    const res = Array(n).fill(0);

    for (let i = 0; i < n; i++) {
        res[i] = (b + m);
        m += b;
        b += (boxes.charCodeAt(i) - 48);
    }

    b = m = 0;
    for (let i = n - 1; i >= 0; i--) {
        res[i] += (b + m);
        m += b;
        b += (boxes.charCodeAt(i) - 48);
    }
    return res;
};