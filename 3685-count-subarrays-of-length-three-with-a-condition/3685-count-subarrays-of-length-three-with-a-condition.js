/**
 * @param {number[]} nums
 * @return {number}
 */
var countSubarrays = function(nums) {
    let cnt = 0;
    let n = nums.length;
    for (let i = 1; i < n - 1; ++i)
        cnt += (2 * (nums[i - 1] + nums[i + 1]) == nums[i]) ? 1 : 0;
    return cnt
};