func largestCombination(candidates []int) int {
	freq := make([]int, 32)
	ans := 0
	for _, num := range candidates {
		for i := 0; i < 32; i++ {
		    mask := 1 << i
		    if mask & num != 0 {
			    freq[i]++
		    }
		    ans = max(ans, freq[i])
	    }
	}

	return ans
}