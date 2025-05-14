func canPartitionGrid(grid [][]int) bool {
    n, m := len(grid), len(grid[0])
    rowSum, colSum := make([]int64, n), make([]int64, m)
    var tot int64

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            tot += int64(grid[i][j])
            rowSum[i] += int64(grid[i][j])
            colSum[j] += int64(grid[i][j])
        }
    }
    if tot & 1 != 0 {
        return false
    }

    var prev int64
    for i := 0; i < n - 1; i++ {
        prev += rowSum[i]
        if prev << 1 == tot {
            return true
        }
    }

    prev = 0
    for i := 0; i < m - 1; i++ {
        prev += colSum[i]
        if prev << 1 == tot {
            return true
        }
    }

    return false
}