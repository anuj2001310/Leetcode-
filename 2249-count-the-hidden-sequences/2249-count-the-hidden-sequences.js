/**
 * @param {number[]} differences
 * @param {number} lower
 * @param {number} upper
 * @return {number}
 */
var numberOfArrays = function(differences, lower, upper) {
    let curr = 0, min = 0, max = 0;
    for (let d of differences) {
        curr += d;
        min = (min < curr) ? min : curr;
        max = (max > curr) ? max : curr;

        if ((upper - max) - (lower - min) + 1 <= 0)
            return 0;
    }
    return (upper - lower) - (max - min) + 1;
};