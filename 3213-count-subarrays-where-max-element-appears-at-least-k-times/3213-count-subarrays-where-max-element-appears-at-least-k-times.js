/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    let ANS = 0;
    let n = nums.length;
    let l = 0, r = 0; curr = 0;
    let m = Math.max(...nums)
    for (; r < n; ++r) {
        curr += (nums[r] == m) ? 1 : 0;
        while (curr >= k)
            curr -= (nums[l++] == m) ? 1 : 0;
        ANS += l;
    }
    return ANS;
};