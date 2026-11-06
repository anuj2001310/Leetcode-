func countServers(n int, logs [][]int, x int, queries []int) []int {
	sort.Slice(logs, func(i, j int) bool {
		return logs[i][1] < logs[j][1]
	})

	q := make([][2]int, len(queries))
	for i, t := range queries {
		q[i] = [2]int{t, i}
	}
	sort.Slice(q, func(i, j int) bool {
		return q[i][0] < q[j][0]
	})

	cnt := make([]int, n+1)
	ans := make([]int, len(queries))
	l, r, active := 0, 0, 0

	for _, p := range q {
		t, i := p[0], p[1]

		for r < len(logs) && logs[r][1] <= t {
			id := logs[r][0]
			cnt[id]++
			if cnt[id] == 1 {
				active++
			}
			r++
		}

		for l < r && logs[l][1] < t-x {
			id := logs[l][0]
			cnt[id]--
			if cnt[id] == 0 {
				active--
			}
			l++
		}

		ans[i] = n - active
	}

	return ans
}