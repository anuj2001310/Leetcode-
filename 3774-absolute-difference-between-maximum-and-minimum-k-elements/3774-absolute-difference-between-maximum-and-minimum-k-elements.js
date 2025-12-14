/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var absDifference = function(nums, k) {
    nums.sort((a, b) => {
        return a - b;
    });
    //console.log(nums);
    let s = 0, f = 0;
    let n = nums.length;
    for (let i = 0; i < k; i++) {
        s += nums[i];
        f += nums[n - i - 1];
    }
    return f - s;
};