/**
 * @param {number[]} nums
 * @return {number}
 */
var findScore = function (nums) {
    let ans = 0;
    for (let i = 0, n = nums.length; i < n; i += 2) {
        let i0 = i;
        while (i + 1 < n && nums[i] > nums[i + 1])
            ++i;
        for (let j = i; j >= i0; j -= 2)
            ans += nums[j];
    }
    return ans;
};