/**
 * @param {string} s
 * @return {number}
 */
var vowelConsonantScore = function (s) {
    let str = "aeiou";
    let v = 0, c = 0;
    for (let ch of s) {
        if (str.includes(ch))
            v += 1
        else if (ch >= 'a' && ch <= 'z' && !str.includes(ch))
            c += 1

    }
    if (c === 0)
        return 0;
    return Math.floor(v / c);
};