/**
 * @param {string} s
 * @return {string}
 */
var trimTrailingVowels = function (s) {
    const vow = (n) => {
        let str = "aeiou";
        return str.includes(n);
    }
    let n = s.length;
    let id = n - 1;
    while (id >= 0) {
        if (!vow(s[id]))
            break;
        id--;
    }
    return s.slice(0, id + 1);
};