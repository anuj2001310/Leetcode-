package main

func getFood(grid [][]byte) int {
	n := len(grid)
	m := len(grid[0])

	dirs := [][]int{
		{-1, 0},
		{0, 1},
		{1, 0},
		{0, -1},
	}

	visited := make([][]bool, n)
	for i := range visited {
		visited[i] = make([]bool, m)
	}

	type Node struct {
		dist int
		r    int
		c    int
	}

	queue := []Node{}

	// Find starting position '*'
	found := false
	for i := 0; i < n && !found; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == '*' {
				queue = append(queue, Node{0, i, j})
				visited[i][j] = true
				found = true
				break
			}
		}
	}

	head := 0 // pointer instead of removing from slice

	for head < len(queue) {
		curr := queue[head]
		head++

		if grid[curr.r][curr.c] == '#' {
			return curr.dist
		}

		for _, d := range dirs {
			nr := curr.r + d[0]
			nc := curr.c + d[1]

			if nr >= 0 && nr < n &&
				nc >= 0 && nc < m &&
				!visited[nr][nc] &&
				grid[nr][nc] != 'X' {

				visited[nr][nc] = true
				queue = append(queue, Node{curr.dist + 1, nr, nc})
			}
		}
	}

	return -1
}
