func setZeroes(matrix [][]int)  {
    n := len(matrix)
    m := len(matrix[0])

    row := make([]bool, n)
    col := make([]bool, m)

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if matrix[i][j] == 0 {
                row[i] = true
                col[j] = true
            }
        }
    }

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if row[i] || col[j] {
                matrix[i][j] = 0
            }
        }
    }
}