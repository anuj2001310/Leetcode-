/**
 * @param {number[]} nums
 * @param {number} maximumBit
 * @return {number[]}
 */
var getMaximumXor = function(nums, maximumBit) {
    let n = nums.length
    let b = (1 << maximumBit) - 1
    const arr = Array(n).fill(0)
    let xor = 0

    for(let num of nums) 
        xor ^= num
    
    for (let i = 0; i < n; ++i) {
        arr[i] = xor ^ b
        xor ^= nums[n - i - 1]
    }
    return arr
};