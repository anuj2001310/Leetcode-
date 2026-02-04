func maxSumTrionic(nums []int) int64 {
	const INF = -1 << 50
    n := len(nums)
	result, a, b, c := INF, INF, INF, INF
	prev := nums[0]
	for i := 1; i < n; i++ {
		curr := nums[i]
		na, nb, nc := INF, INF, INF
		if curr > prev {
			na = max(a, prev) + curr
			nc = max(b, c) + curr
		} else if curr < prev { 
			nb = max(a, b) + curr
		}
		a, b, c = na, nb, nc
		result = max(result, c)
		prev = curr
	}
	return int64(result)
}