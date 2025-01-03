/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplitArray = function(nums) {
    let rsum = 0, lsum = 0;
    for (let num of nums)
        rsum += num;
    
    let cnt = 0;
    let n = nums.length;

    for (let i = 0; i < n - 1; ++i) {
        lsum += nums[i];
        rsum -= nums[i];

        if (lsum >= rsum)
            cnt++;
    }
    return cnt
};