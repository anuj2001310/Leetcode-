/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumPossibleSize = function(nums) {
    let n = nums.length, cnt = 1;
    let num = nums[0];
    for (let i = 1; i < n; ++i) {
        if (nums[i] >= num) {
            num = nums[i];
            cnt++;
        }
    }
    return cnt;
};