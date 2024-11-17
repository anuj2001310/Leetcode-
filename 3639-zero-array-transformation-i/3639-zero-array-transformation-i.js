/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean}
 */
var isZeroArray = function(nums, queries) {
    let n = nums.length
    const del = Array(n + 1).fill(0)
    
    for (let q of queries) {
        let l = q[0]
        let r = q[1]
        del[l]++
        del[r + 1]--
    }
    
    for (let i = 1; i <= n; ++i)
        del[i] += del[i - 1]
    
    for (let i = 0; i < n; ++i)
        if (del[i] < nums[i])
            return false
    return true
};