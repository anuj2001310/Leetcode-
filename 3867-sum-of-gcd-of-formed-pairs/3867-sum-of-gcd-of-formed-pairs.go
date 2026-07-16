func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
func gcdSum(nums []int) int64 {
	n := len(nums)
	curr := nums[0]

	for i := 0; i < n; i++ {
		if nums[i] > curr {
			curr = nums[i]
		}
		nums[i] = gcd(nums[i], curr)
	}

	sort.Ints(nums)
	var s int64

	u, v := 0, n-1
	for u < v {
		s += int64(gcd(nums[u], nums[v]))
		u++
		v--
	}
	return s
}