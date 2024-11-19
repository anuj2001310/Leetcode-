/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumSubarraySum = function (nums, k) {
    let start = 0, end = 0, sum = 0, maxSum = 0, hashSet = new Set();
    while (end < nums.length) {
        while (hashSet.has(nums[end])) {
            hashSet.delete(nums[start]);
            sum -= nums[start];
            start++;
        }

        sum += nums[end];
        hashSet.add(nums[end]);

        if (end - start + 1 == k) {
            maxSum = Math.max(maxSum, sum);
            hashSet.delete(nums[start]);
            sum -= nums[start];
            start++;
        }

        end++;
    }
    return maxSum;
};