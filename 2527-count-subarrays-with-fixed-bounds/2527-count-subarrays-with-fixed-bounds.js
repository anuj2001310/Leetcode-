/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    let n = nums.length;
    let cnt = 0;
    let left_bnd = -1, last_min = -1, last_max = -1;
    for (let i = 0; i < n; ++i) {
        if (nums[i] >= minK && nums[i] <= maxK) {
            last_min = (nums[i] == minK) ? i : last_min;
            last_max = (nums[i] == maxK) ? i : last_max;
            cnt += Math.max(0, Math.min(last_min, last_max) - left_bnd);
        }
        else {
            left_bnd = i;
            last_min = -1;
            last_max = -1;
        }
    }
    return cnt;
};