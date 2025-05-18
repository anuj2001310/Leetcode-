/**
 * @param {number[]} nums
 * @return {number}
 */
var smallestIndex = function(nums) {
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        let num = nums[i], sum = 0;
        for (; num != 0; ) {
            sum += num % 10;
            if (sum > i)
                break;
            num = Math.floor(num /10);
        }
        if (sum == i)
            return i;
    }
    return -1;
};