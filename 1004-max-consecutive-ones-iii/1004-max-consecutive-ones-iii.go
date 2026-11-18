func longestOnes(nums []int, k int) int {
	n := len(nums)
	r, l, ans, zero := 0, 0, -1, 0
	for ; r < n; r++ {
		if nums[r] == 0 {
			zero++
		}

		for zero > k {
			if nums[l] == 0 {
				zero--
			}
            l++
		}
		curr := r - l + 1
		if curr > ans {
			ans = curr
		}

	}
	return ans
}