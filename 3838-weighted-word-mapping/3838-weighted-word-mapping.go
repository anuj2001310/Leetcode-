func mapWordWeights(words []string, weights []int) string {
	n := len(words)
	ans := make([]byte, n)

	for i, word := range words {
		sum := 0
		for _, ch := range word {
			sum += weights[ch-'a']
		}

		r := 25 - (sum % 26)
		ans[i] = byte('a' + r)
	}

	return string(ans)
}