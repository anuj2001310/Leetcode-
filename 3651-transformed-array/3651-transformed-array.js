/**
 * @param {number[]} nums
 * @return {number[]}
 */
var constructTransformedArray = function(nums) {
    const res = []
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        let idx = (i + nums[i] % n + n) % n;
        res.push (nums[idx]);
    }

    return res;
};