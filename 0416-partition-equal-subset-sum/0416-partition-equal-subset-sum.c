#include<stdio.h>
#include<stdlib.h>

bool memo(int* nums, int** dp, int sum, int idx, int n) {
    if (sum == 0)
        return true;
    
    if (idx >= n)
        return false;
    
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    
    bool pick = false, no_pick = false;

    if (nums[idx] <= sum)
        pick = memo(nums, dp, sum - nums[idx], idx + 1, n);

    no_pick = memo(nums, dp, sum, idx + 1, n);

    return dp[idx][sum] = (pick || no_pick);
}

bool canPartition(int* nums, int numsSize) {
    int sum = 0;

    for (int i = 0; i < numsSize; i++)
        sum += nums[i];

    if (sum & 1)
        return false;
        
    int** dp = (int**)malloc(sizeof(int*) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        dp[i] = (int*)malloc(sizeof(int) * ((sum >> 1) + 1));
        for (int j = 0; j < ((sum >> 1) + 1); ++j)
            dp[i][j] = -1;
    }

    return memo(nums, dp, sum >> 1, 0, numsSize);
}