func countIslands(grid [][]int, k int) int {
    n, m := len(grid), len(grid[0])
    
    vis := make([][]bool, n)
    
    for i := 0; i < n; i++ {
        vis[i] = make([]bool, m)
    }
    var dfs func(r, c int) int64
    
    dfs = func(r, c int) int64 {
        if r >= n || r < 0 || c >= m || c < 0 || vis[r][c] || grid[r][c] == 0 {
            return 0
        }
        
        vis[r][c] = true
        var sum int64
        
        sum = int64(grid[r][c])
        
        sum += int64(dfs(r - 1, c))
        sum += int64(dfs(r, c + 1))
        sum += int64(dfs(r + 1, c))
        sum += int64(dfs(r, c - 1))
        
        return sum
    }

    cnt := 0
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if !vis[i][j] && grid[i][j] > 0 {
                val := dfs (i, j)
                if int(val) % k == 0 {
                    cnt++
                }
            }       
        }
    }
    return cnt
}