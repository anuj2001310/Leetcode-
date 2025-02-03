/**
 * @param {number[]} nums
 * @return {number}
 */
var longestMonotonicSubarray = function(nums) {
    let n = nums.length;
    const inc = Array(n).fill(1);
    const dec = Array(n).fill(1);
    const Max = (a, b) => {
        if (a > b)
            return a;
        return b;
    }
    for (let i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1])
            inc[i] = inc[i - 1] + 1;
        if (nums[i] < nums[i - 1]) 
            dec[i] = dec[i - 1] + 1;
    }

    let ans = 0;
    for (let i = 0; i < n; i++) {
        ans = Max (ans, inc[i]);
        ans = Max (ans, dec[i]);
    }
    return ans;
};