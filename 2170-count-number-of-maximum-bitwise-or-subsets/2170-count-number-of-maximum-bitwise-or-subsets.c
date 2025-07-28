int countMaxOrSubsets(int* nums, int numsSize) {
    int ans = 0;
    int dp[1 << 17] = {};

    dp[0] = 1;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        for (int j = ans; j >= 0; j--)
            dp[j | num] += dp[j];
        
        ans |= num;
    } 
    return dp[ans];
}