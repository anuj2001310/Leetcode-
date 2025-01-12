func zigzagTraversal(grid [][]int) []int {
    if len(grid) == 0 {
        return []int{}
    }
    ret := make([]int, 0)
    l := len(grid[0])
    l = l % 2
    for i := range grid {
        if i % 2 == 0 {
            for j := 0; j < len(grid[0]); j += 2 {
                ret = append(ret, grid[i][j])
            }
        } else {
            for j := len(grid[0]) - l - 1; j >= 0; j -= 2 {
                ret = append(ret, grid[i][j])
            }
        }
    }
    return ret
}