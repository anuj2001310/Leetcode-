/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function (nums) {
    const n = nums.length;
    const sum = nums.reduce((acc, curr) => acc + curr, 0);

    if (sum & 1 != 0) return false;

    const target = sum >> 1;

    // Initialize DP table with -1
    const dp = Array(n).fill().map(() => Array(target + 1).fill(-1));
    //console.log(dp);

    const memo = (nums, dp, sum, idx) => {
        // Base cases
        if (sum === 0) return true;
        if (idx >= nums.length) return false;

        // If already computed
        if (dp[idx][sum] !== -1) return dp[idx][sum];

        let pick = false;
        let nonPick = false;

        // Try picking current number if it doesn't exceed target sum
        if (nums[idx] <= sum) {
            pick = memo(nums, dp, sum - nums[idx], idx + 1);
        }

        // Try not picking current number
        nonPick = memo(nums, dp, sum, idx + 1);

        // Store and return result
        dp[idx][sum] = pick || nonPick;
        return dp[idx][sum];
    }

    return memo(nums, dp, target, 0);

};
