func minCost(grid [][]int) int {
     m, n := len(grid), len(grid[0])
    visited := make([][]bool, m)
    for i, _ := range visited {
        visited[i] = make([]bool, n)
    }
    dirs := [][]int {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    }
    queue := [][]int{}
    dist := 0
    var dfs func(i, j int)
    dfs = func(i, j int) {
        if i < 0 || i >= m {
            return
        }
        if j < 0 || j >= n {
            return
        }
        if visited[i][j] {
            return
        }
        visited[i][j] = true
        queue = append(queue, []int{i, j, dist})
        dir := dirs[grid[i][j] - 1]
        dfs(i + dir[0], j + dir[1])
    }
    dfs(0, 0)
    for len(queue) > 0 {
        top := queue[0]
        queue = queue[1: ]
        if top[0] == m - 1 && top[1] == n - 1 {
            return top[2]
        }
        dist = top[2] + 1
        for _, dir := range dirs {
            dfs(top[0] + dir[0], top[1] + dir[1])
        }
    }
    return 0
}