func maxSum(grid [][]int, limits []int, k int) int64 {
    list := make([]int, 0)
    for _, row := range grid {
        sort.Slice(row, func(i, j int) bool {
            return row[i] > row[j]
        })
    }
    for i := 0; i < len(limits); i++ {
        for j := 0; j < limits[i]; j++ {
            list = append(list, grid[i][j])
        }
    }

    sort.Slice(list, func(i, j int) bool {
        return list[i] > list[j]
    })

    var sum int64
    for i := 0; i < k; i++ {
        sum += int64(list[i])
    }
    
    return sum
}