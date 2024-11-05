/**
 * @param {string} s
 * @return {number}
 */
var minChanges = function(s) {
    var cnt = 0
    for (let i = 0; i < s.length; i += 2)
        if (s.at(i) !== s.at(i + 1))
            cnt++
    
    return cnt
};