/**
 * @param {number[]} nums
 * @return {number}
 */
var splitArray = function(nums) {
    const isPrime = (num) => {
        if (num <= 1)
            return false;
        for (let i = 2; i <= Math.sqrt(num); ++i) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    let sumA = 0, sumB = 0;
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        if (isPrime(i))
            sumA += nums[i];
        else
            sumB += nums[i];
    }
    return Math.abs(sumA - sumB);
};