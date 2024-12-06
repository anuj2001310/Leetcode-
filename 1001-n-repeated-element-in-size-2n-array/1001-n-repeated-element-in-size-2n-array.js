/**
 * @param {number[]} nums
 * @return {number}
 */
var repeatedNTimes = function (nums) {
    let n = nums.length / 2;
    let c = 0
    for (let i = 0; i < nums.length; i++) {
        c = 0
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] == nums[j]) {
                c++
            }
        }
        if (c == n - 1) {
            return nums[i]
        }
    }
};