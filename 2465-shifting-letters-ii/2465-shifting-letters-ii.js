/**
 * @param {string} s
 * @param {number[][]} shifts
 * @return {string}
 */
var shiftingLetters = function (s, shifts) {
    const n = s.length;
    const prefix = new Array(n + 1).fill(0);

    for (let shift of shifts) {
        const [st, ed, dr] = shift;
        prefix[st] += (2 * dr - 1);
        if (ed + 1 < n) {
            prefix[ed + 1] -= (2 * dr - 1);
        }
    }

    let sb = [];
    let currShift = 0;

    for (let i = 0; i < n; i++) {
        currShift = (currShift + prefix[i]) % 26;
        const ch = String.fromCharCode(((s.charCodeAt(i) - 'a'.charCodeAt(0) + currShift + 26) % 26) + 'a'.charCodeAt(0));
        sb.push(ch);
    }

    return sb.join('');

};