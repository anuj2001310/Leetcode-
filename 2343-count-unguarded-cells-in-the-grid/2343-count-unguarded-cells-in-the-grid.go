func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {
	//Create a 2-D array using slices (make)
	vis := make([][]int, m)
	for i := 0; i < m; i++ {
		vis[i] = make([]int, n)
	}
	//Mark the guards
	for i := 0; i < len(guards); i++ {
		r := guards[i][0]
		c := guards[i][1]
		vis[r][c] = 2
	}
	//Mark the walls
	for i := 0; i < len(walls); i++ {
		r := walls[i][0]
		c := walls[i][1]
		vis[r][c] = 3
	}

	for i := 0; i < len(guards); i++ {
		r := guards[i][0]
		c := guards[i][1]
		left, right := c - 1, c + 1
		up, down := r - 1, r + 1

		//Left-Movement
		for left >= 0 {
			if vis[r][left] == 3 || vis[r][left] == 2 {
				break
			}
			vis[r][left] = 1
			left--
		}

		//Right-Movement
		for right < n {
			if vis[r][right] == 3 || vis[r][right] == 2 {
				break
			}
			vis[r][right] = 1
			right++
		}

		//Up-Movement
		for up >= 0 {
			if vis[up][c] == 3 || vis[up][c] == 2 {
				break
			}
			vis[up][c] = 1
			up--
		}

		//Down-Movement
		for down < m {
			if vis[down][c] == 3 || vis[down][c] == 2 {
				break
			}
			vis[down][c] = 1
			down++
		}
	}
	cnt := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if vis[i][j] == 0 {
				cnt++
			}
		}
	}
	return cnt
}