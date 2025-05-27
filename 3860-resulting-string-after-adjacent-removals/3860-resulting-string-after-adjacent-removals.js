/**
 * @param {string} s
 * @return {string}
 */
var resultingString = function(s) {
    const stk = [];
    for (let ch of s) {
        let top = stk[stk.length - 1]
        if (
            stk.length &&
            (Math.abs(ch.charCodeAt(0) - top.charCodeAt(0)) === 1 ||
             Math.abs(ch.charCodeAt(0) - top.charCodeAt(0)) === 25)
        )
            stk.pop()
        else
            stk.push(ch)
    }
    
    return stk.join('');
};