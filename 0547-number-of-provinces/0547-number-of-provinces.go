func findCircleNum(isConnected [][]int) int {
    V := len(isConnected)
	vis := make([]bool, V)
	var dfs func(int)
	dfs = func(node int) {
		vis[node] = true
		for j, x := range isConnected[node] {
			if !vis[j] && x == 1 {
				dfs(j)
			}
		}
	}
    ans := 0
	for i, v := range vis {
		if !v {
			ans++
			dfs(i)
		}
	}
	return  ans 
}