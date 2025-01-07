/**
 * @param {string[]} words
 * @return {string[]}
 */
var stringMatching = function (words) {
    const set = new Set();
    let n = words.length;

    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i != j) {
                if (words[i].includes(words[j]))
                    set.add(words[j]);
            }
        }
    }
    const res = []
    for (let st of set)
        res.push(st);
    return res
};