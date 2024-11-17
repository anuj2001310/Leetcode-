func findMissingAndRepeatedValues(grid [][]int) []int {
    n := len(grid)
    square := make([]int, n * n + 1)
    for i := 0; i < n; i++ {
        for j := 0; j < len(grid[i]); j++ {
            square[grid[i][j]]++
        }
    }

    ans := make([]int, 2)
    for i := 0; i < len(square); i++ {
        if square[i] == 2 {
            ans[0] = i
        }
        if square[i] == 0 {
            ans[1] = i
        }
    }
    return ans
}