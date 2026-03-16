/**
 * @param {number[]} nums
 * @return {number}
 */
var firstUniqueEven = function(nums) {
    let n = nums.length;
    const arr = new Array(101).fill(0);
    for (let num of nums)
        arr[num]++;
    
    for (let i = 0; i < n; ++i) {
        if ((nums[i] & 1) == 0 && arr[nums[i]] == 1)
            return nums[i]
    }
    return -1;
};