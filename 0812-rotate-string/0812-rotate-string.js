/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function (s, goal) {
    if (s.length !== goal.length)
        return false

    let str = s + s
    if (str.includes(goal))
        return true

    return false
};