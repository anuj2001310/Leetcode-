func smallestDivisor(nums []int, k int) int {
	l, h := 1, 0
	for _, num := range nums {
		if num > h {
			h = num
		}
	}

	possible := func(d int) bool {
		s := 0
		for _, num := range nums {
			s += (num + d - 1) / d
		}
		return s <= k
	}

	for l <= h {
		m := l + (h-l)/2
		if possible(m) {
			h = m - 1
		} else {
			l = m + 1
		}
	}
	return l
}
