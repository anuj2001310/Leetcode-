func maxKDivisibleComponents(n int, edges [][]int, values []int, k int) int {
	al := make([][]int, n)
	cnt := make([]int, n)
	res := 0

	for _, e := range edges {
		al[e[0]] = append(al[e[0]], e[1])
		al[e[1]] = append(al[e[1]], e[0])
	}

	q := make([]int, 0)
	for i := 0; i < n; i++ {
		cnt[i] = len(al[i])
		if cnt[i] < 2 {
			q = append(q, i)
		}
	}
    
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		cnt[i]--

		if values[i]%k == 0 {
			res++
		}

		for _, j := range al[i] {
			if cnt[j] > 0 {
				values[j] += values[i] % k
				cnt[j]--
				if cnt[j] == 1 {
					q = append(q, j)
				}
			}
		}
	}
	return res
}