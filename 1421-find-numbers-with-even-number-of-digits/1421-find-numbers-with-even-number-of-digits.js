/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    var cnt = 0
    for (let num of nums) {
        let size = 0
        let n = num
        while (n != 0) {
            size++
            n = Math.floor(n / 10)
        }
        if ((size & 1) == 0)
            cnt++
    }
    return cnt
};