/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canSortArray = function (nums) {
    const count = (n) => {
        let bit = 0
        while (n) {
            bit++
            n = n & (n - 1)
        }
        return bit
    }
    let l = 0, h = nums[0]
    let bit = false
    for (let i = 1; i < nums.length; ++i) {
        bit = (count(h) != count(nums[i]))
        if (bit)
            l = h
        if (nums[i] > h)
            h = nums[i]
        if (nums[i] < l)
            return false
    }
    return true
};