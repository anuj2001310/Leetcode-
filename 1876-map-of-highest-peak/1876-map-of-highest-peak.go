package main

import (
	"container/list"
)

type Pair struct {
	first  int
	second int
}

func highestPeak(isWater [][]int) [][]int {
	n := len(isWater)
	m := len(isWater[0])
	height := make([][]int, n)

	for i := 0; i < n; i++ {
		height[i] = make([]int, m)
		for j := 0; j < m; j++ {
			height[i][j] = -1
		}
	}

	dirs := [][2]int{
		{-1, 0},
		{0, 1},
		{1, 0},
		{0, -1},
	}

	q := list.New()

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if isWater[i][j] == 1 {
				q.PushBack(Pair{i, j})
				height[i][j] = 0
			}
		}
	}

	for q.Len() > 0 {
		element := q.Front()
		q.Remove(element)
		pair := element.Value.(Pair)
		r, c := pair.first, pair.second

		for _, dir := range dirs {
			nr, nc := r+dir[0], c+dir[1]
			if nr >= 0 && nr < n && nc >= 0 && nc < m && height[nr][nc] == -1 {
				height[nr][nc] = height[r][c] + 1
				q.PushBack(Pair{nr, nc})
			}
		}
	}

	return height
}
