package main

import "fmt"

type Solution struct{}

func memo(nums []int, dp [][]int, sum, idx int) bool {

    if sum == 0 {
        return true
    }
    if idx >= len(nums) {
        return false
    }
    
    if dp[idx][sum] != -1 {
        return dp[idx][sum] == 1
    }
    
    pick := false
    nonPick := false

    if nums[idx] <= sum {
        pick = memo(nums, dp, sum-nums[idx], idx+1)
    }
    
    nonPick = memo(nums, dp, sum, idx+1)
    
    if pick || nonPick {
        dp[idx][sum] = 1
    } else {
        dp[idx][sum] = 0
    }
    
    return pick || nonPick
}

func canPartition(nums []int) bool {
    n := len(nums)
    sum := 0
    for _, num := range nums {
        sum += num
    }
    
    if sum & 1 != 0 {
        return false
    }
    
    target := sum >> 1
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, target + 1)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    
    return memo(nums, dp, target, 0)
}