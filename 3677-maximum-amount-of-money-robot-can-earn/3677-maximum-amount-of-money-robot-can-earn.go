func maximumAmount(coins [][]int) int {
    if len(coins) == 0 {
        return 0
    }

    m, n := len(coins), len(coins[0])
    dp := make([][][]int, m)
    for i := range dp {
        dp[i] = make([][]int, n)
        for j := range dp[i] {
            dp[i][j] = make([]int, 3)
        }
    }
    
    dp[0][0][0] = coins[0][0]
    if coins[0][0] > 0 {
        dp[0][0][1] = coins[0][0]
        dp[0][0][2] = coins[0][0]
    }
    for i := range coins {
        for j := range coins[i] {
            if i == 0 && j == 0 {
                continue
            }
            c := coins[i][j]
            if i == 0 {
                dp[i][j][0] = dp[i][ j - 1][0] + c
                dp[i][j][1] = max(dp[i][j - 1][1] + c, dp[i][j - 1][0])
                dp[i][j][2] = max(dp[i][j - 1][2] + c, dp[i][j - 1][1])
                continue
            }
            
            if j == 0 {
                dp[i][j][0] = dp[i - 1][j][0] + c
                dp[i][j][1] = max(dp[i - 1][j][1] + c, dp[i - 1][j][0])
                dp[i][j][2] = max(dp[i - 1][j][2] + c, dp[i - 1][j][1])
                continue
            }
            
            dp[i][j][0] = max(dp[i - 1][j][0] + c, dp[i][j - 1][0] + c)
            dp[i][j][1] = max(max(dp[i][j - 1][1] + c, dp[i][j - 1][0]), max(dp[i - 1][j][1] + c, dp[i - 1][j][0]))
            dp[i][j][2] = max(max(dp[i][j - 1][2] + c, dp[i][j - 1][1]), max(dp[i - 1][j][2] + c, dp[i - 1][j][1]))
        }
    }
    return max(dp[m - 1][n - 1][0], max(dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]))
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}


func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}