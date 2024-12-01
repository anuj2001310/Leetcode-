/**
 * @param {number[]} arr
 * @return {boolean}
 */
var checkIfExist = function (arr) {
    let chekMap = {};

    for (let num of arr) {
        if (chekMap[num << 1] || ((num & 1) === 0 && chekMap[num >> 1])) {
            return true;
        }
        chekMap[num] = true;
    }
    return false;
};