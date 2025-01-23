func countServers(grid [][]int) int {
    n := len(grid)
    m := len(grid[0])

    ans := 0
    row := make([]int, m)
    l := make([]int, n)
    for i := range l {
        l[i] = -1
    }

    for r := 0; r < n; r++ {
        s := 0
        for c := 0; c < m; c++ {
            if grid[r][c] == 1 {
                s++
                row[c]++
                l[r] = c
            }
        }

        if s != 1 {
            ans += s
            l[r] = -1
        }
    }

    for r := 0; r < n; r++ {
        if l[r] != -1 && row[l[r]] > 1 {
            ans++
        }
    }

    return ans
}
