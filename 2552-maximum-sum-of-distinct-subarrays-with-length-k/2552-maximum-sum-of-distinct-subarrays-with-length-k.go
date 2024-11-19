func maximumSubarraySum(nums []int, k int) int64 {
	l, r := 0, 0
	vals := make(map[int]bool, k)
	s := 0

	mx := 0

	for r < len(nums) {
		for l < r && (len(vals) >= k || vals[nums[r]]) {
			delete(vals, nums[l])
			s -= nums[l]
			l++
		}

		vals[nums[r]] = true
		s += nums[r]
		r++

		if len(vals) == k {
			mx = max(mx, s)
		}
	}

	return int64(mx)
}