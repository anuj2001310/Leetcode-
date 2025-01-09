/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function(words, pref) {
    let cnt = 0;
    for (let st of words)
        if (st.startsWith(pref))
            cnt++;
    return cnt
};