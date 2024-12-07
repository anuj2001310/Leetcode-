func maxAreaOfIsland(grid [][]int) int {
    var dfs func(grid [][]int, x, y int) int

	dfs = func(grid [][]int, x, y int) int {
		if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[0]) || grid[x][y] == 0 {
			return 0
		}
		grid[x][y] = 0
		count := 1
		count += dfs(grid, x+1, y)
		count += dfs(grid, x-1, y)
		count += dfs(grid, x, y+1)
		count += dfs(grid, x, y-1)
		return count
	}
	count := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] != 0 {
				comp := dfs(grid, i, j)
				if comp > count {
					count = comp
				}
			}
		}
	}
	return count
}