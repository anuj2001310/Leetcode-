/**
 * @param {string[]} instructions
 * @param {number[]} values
 * @return {number}
 */
var calculateScore = function(instructions, values) {
    let n = values.length;
    let sum = 0;
    let s = new Set()
    for (let i = 0; i < n && i >= 0 && !s.has(i); ) {
        s.add(i);
        if (instructions[i] == "add") {
            sum += values[i];
            i++;
        }
        else
            i += values[i];
    }
    return sum;
};