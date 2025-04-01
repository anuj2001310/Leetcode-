func Max(a, b int64) int64 {
    if a < b {
        return b
    }
    return a
}

func memo(questions [][]int, dp []int64, idx, n int) int64 {
    if idx >= n {
        return 0
    }
    if dp[idx] != -1 {
        return dp[idx]
    }
    var take int64 = int64(questions[idx][0])
    nidx := idx + questions[idx][1] + 1
    if nidx < n {
        take += memo (questions, dp, nidx, n)
    }
    skip := memo (questions, dp, idx + 1, n)
    
    dp[idx] = Max(take, skip)
    return dp[idx]
}

func mostPoints(questions [][]int) int64 {
    n := len(questions)
    dp := make([]int64, (n + 1))
    
    for i, _ := range dp {
        dp[i] = -1
    }
    
    return memo(questions, dp, 0, n)
}