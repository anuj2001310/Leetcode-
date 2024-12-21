package main

import "fmt"

const MOD = 1000000007
const MAX_XOR_VALUE = 16

func solve(grid [][]int, i, j, val, k int, dp [][][]int) int {
    if i == 0 && j == 0 {
        if (val ^ grid[0][0]) == k {
            return 1
        }
        return 0
    }

    if i < 0 || j < 0 {
        return 0
    }

    if dp[i][j][val] != -1 {
        return dp[i][j][val]
    }

    up := solve(grid, i - 1, j, val ^ grid[i][j], k, dp)
    left := solve(grid, i, j - 1, val ^ grid[i][j], k, dp)

    dp[i][j][val] = (up + left) % MOD
    return dp[i][j][val]
}

func countPathsWithXorValue(grid [][]int, k int) int {
    n := len(grid)
    m := len(grid[0])

    dp := make([][][]int, n)
    for i := range dp {
        dp[i] = make([][]int, m)
        for j := range dp[i] {
            dp[i][j] = make([]int, MAX_XOR_VALUE)
            for l := 0; l < MAX_XOR_VALUE; l++ {
                dp[i][j][l] = -1
            }
        }
    }

    ans := solve(grid, n - 1, m - 1, 0, k, dp)

    return ans % MOD
}