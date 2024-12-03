/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function(s, spaces) {
    let words = [], endIdx = spaces[0], startIdx = 0;
    
    for (let i = 0; i <= spaces.length; i++) {
        let word = s.slice(startIdx, endIdx)
        words.push(word)
        startIdx = spaces[i];
        endIdx = spaces[i + 1];
    }
    
    return words.join(" ")
};