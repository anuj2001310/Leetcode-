func maxNumberOfBalloons(text string) int {
	n, res := len(text), math.MaxInt
	s := "ballon"
	freq := make([]int, 26)

	for i := 0; i < n; i++ {
		id := int(text[i] - 'a')
		freq[id]++
	}

	for _, ch := range s {
		id := int(ch - 'a')
		if ch == 'l' || ch == 'o' {
			res = min(res, freq[id]/2)
		} else {
			res = min(res, freq[id])
		}
	}
	return res
}