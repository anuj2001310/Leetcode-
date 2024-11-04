/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function (word) {
    var comp = ""
    var i = 0
    while (i < word.length) {
        let cnt = 1
        let curr = word[i]
        while ((i + 1) < word.length && word.at(i + 1) === curr && cnt < 9) {
            cnt++
            i++
        }
        comp = comp.concat('', `${cnt}`)
        comp = comp.concat('', curr)
        i++
    }
    return comp
};