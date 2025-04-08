/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    var n = nums.length;
    let arr = Array(101).fill(false);
    for (let i = n - 1; i >= 0; i--) {
        if (arr[nums[i]])
            return Math.ceil((i + 1) / 3);
        arr[nums[i]] = true;
    }
    return 0;
};