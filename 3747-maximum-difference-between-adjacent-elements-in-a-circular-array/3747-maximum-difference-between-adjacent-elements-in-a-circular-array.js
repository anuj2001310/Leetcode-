/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAdjacentDistance = function(nums) {
    let n = nums.length;
    let ans = Math.abs(nums[0] - nums[n - 1]);
    for (let i = 1; i < n; i++) {
        let val = Math.abs(nums[i - 1] - nums[i]);
        ans = Math.max(ans, val);
    }
    return ans;
};