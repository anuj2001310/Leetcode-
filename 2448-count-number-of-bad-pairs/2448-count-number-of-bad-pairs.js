/**
 * @param {number[]} nums
 * @return {number}
 */
var countBadPairs = function (a) {
    const { length } = a;
    const m = new Map();
    let p = length * (length - 1) / 2;
    for (let i = 0, d = a[0]; i < a.length; d = a[++i] - i) {
        const t = m.get(d) ?? 0;
        p -= t;
        m.set(d, t + 1);
    }
    return p;
};