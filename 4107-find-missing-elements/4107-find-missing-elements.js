/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findMissingElements = function(nums) {
    let n = nums.length;
    let max = -1;
    let min = 1234567889;
    
    const vis = Array(101).fill(false);
    for (let w = 0; w < n; w++) {
        max = Math.max(max, nums[w]);
        min = Math.min(min, nums[w]);
        vis[nums[w]] = true;
    }
    const arr = []
    for (let i = min; i < max; ++i) {
        if (!vis[i])
            arr.push(i);
    }
    return arr;
};