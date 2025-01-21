package main

import "math"

func gridGame(grid [][]int) int64 {
    m := len(grid[0])
    res := int64(math.MaxInt64)
    
    topSum := int64(0)
    for i := 0; i < m; i++ {
        topSum += int64(grid[0][i])
    }
    
    bottomSum := int64(0)
    
    for i := 0; i < m; i++ {
        topSum -= int64(grid[0][i])
        res = min(res, max(topSum, bottomSum))
        bottomSum += int64(grid[1][i])
    }
    
    return res
}

func min(a, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

func max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}
