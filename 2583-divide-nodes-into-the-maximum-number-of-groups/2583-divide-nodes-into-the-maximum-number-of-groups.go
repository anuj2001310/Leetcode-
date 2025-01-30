func magnificentSets(n int, edges [][]int) int {

	adjList := make([][]int, n)
	for _, edge := range edges {
		adjList[edge[0]-1] = append(adjList[edge[0]-1], edge[1]-1)
		adjList[edge[1]-1] = append(adjList[edge[1]-1], edge[0]-1)
	}

	colors := make([]int, n)
	for idx := range colors {
		colors[idx] = -1
	}

	for node := 0; node < n; node++ {
		if colors[node] == -1 {
			if !isBipartite(node, adjList, &colors, 1) {
				return -1
			}
		}
	}

	levels := make([]int, n)
	for node := 0; node < n; node++ {
		levels[node] = bfs(node, adjList, n)
	}

	maxGroups := 0
	visited := make([]bool, n)
	for node := 0; node < n; node++ {
		if !visited[node] {
			maxGroups += getMaxGroups(node, adjList, &visited, levels)
		}
	}

	return maxGroups

}

func isBipartite(node int, adjList [][]int, colors *[]int, currColor int) bool {

	queue := []int{node}
	(*colors)[node] = currColor

	for len(queue) > 0 {
		currNode := queue[0]
		queue = queue[1:]

		for _, toVisit := range adjList[currNode] {
			if (*colors)[toVisit] == (*colors)[currNode] {
				return false
			} else if (*colors)[toVisit] == -1 {
				(*colors)[toVisit] = 1 - (*colors)[currNode]
				queue = append(queue, toVisit)
			}
		}
	}

	return true

}

func bfs(node int, adjList [][]int, n int) int {

	visited := make([]bool, n)
	queue := []int{node}
	visited[node] = true

	level := 0
	for len(queue) > 0 {
		currLevelNodes := len(queue)
		for currLevelNodes > 0 {
			currNode := queue[0]
			queue = queue[1:]
			for _, toVisit := range adjList[currNode] {
				if !visited[toVisit] {
					visited[toVisit] = true
					queue = append(queue, toVisit)
				}
			}
			currLevelNodes--
		}
		level++
	}

	return level

}

func getMaxGroups(node int, adjList [][]int, visited *[]bool, levels []int) int {

	maxGroups := levels[node]
	(*visited)[node] = true

	for _, toVisit := range adjList[node] {
		if !(*visited)[toVisit] {
			maxGroups = max(maxGroups, getMaxGroups(toVisit, adjList, visited, levels))
		}
	}

	return maxGroups

}