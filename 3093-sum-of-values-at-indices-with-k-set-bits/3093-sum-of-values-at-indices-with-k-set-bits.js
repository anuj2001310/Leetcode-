/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var sumIndicesWithKSetBits = function(nums, k) {
    const bits = (num) => {
        let b = 0
        while (num) {
            num &= (num - 1)
            b++
        }
        return b
    }
    
    var summ = 0
    let n = nums.length
    for (let i = 0; i < n; ++i) {
        if (bits(i) == k)
            summ += nums[i]
    }
    return summ
};