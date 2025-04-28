/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    let res = 0;
    let cnt = 0;
    let sum = 0;
    let n = nums.length, l = 0;
    for (let r = 0; r < n; ++r) {
        sum += nums[r];
        cnt++;
        while (sum * cnt >= k) {
            sum -= nums[l++];
            cnt--;
        }
        res += cnt;
    }
    return res;
};