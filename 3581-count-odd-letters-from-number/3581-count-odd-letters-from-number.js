/**
 * @param {number} n
 * @return {number}
 */
var countOddLetters = function (n) {
    const arr = [
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    ]
    let freq = new Array(26).fill(0);
    for (; n > 0;) {
        let r = n % 10;
        for (let ch of arr[r]) {
            let id = ch.charCodeAt(0) - 97;
            freq[id]++;
        }
        n = Math.floor(n / 10);
    }
    let cnt = 0;
    for (let i = 0; i < 26; i++) {
        if (freq[i] == 0)
            continue;
        cnt += ((freq[i] & 1) > 0 ? 1 : 0);
    }
    return cnt;
};