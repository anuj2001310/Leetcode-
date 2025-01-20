package main

import "fmt"

type Pair struct {
	first  int
	second int
}

func firstCompleteIndex(arr []int, mat [][]int) int {
	n := len(mat)
	m := len(mat[0])
	temp := make([] *Pair, n * m + 1)

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			temp[mat[i][j]] = &Pair{i, j}
		}
	}

	rows := make([]int, n)
	cols := make([]int, m)

	for i := 0; i < n * m; i++ {
		r := temp[arr[i]].first
		c := temp[arr[i]].second
		rows[r]++
		cols[c]++

		if rows[r] == m || cols[c] == n {
			return i
		}
	}

	return -1
}
