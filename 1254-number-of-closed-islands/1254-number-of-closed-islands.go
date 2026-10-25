package main
var dirs = [][]int{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1},
}

func dfs(r, c int, grid [][]int, vis [][]bool, n, m int) {
	vis[r][c] = true
	for i := 0; i < len(dirs); i++ {
		nr, nc := r + dirs[i][0], c + dirs[i][1]
		if nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && !vis[nr][nc] {
			dfs(nr, nc, grid, vis, n, m)
		}
	}
}

func closedIsland(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	vis := make([][]bool, n)

	for i := 0; i < n; i++ {
		vis[i] = make([]bool, m)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if i == 0 || i == n-1 || j == 0 || j == m-1 {
				if grid[i][j] == 0 && !vis[i][j] {
					dfs(i, j, grid, vis, n, m)
				}
			}
		}
	}

	count := 0

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 0 && !vis[i][j] {
				count++
				dfs(i, j, grid, vis, n, m)
			}
		}
	}
    
	return count
}
