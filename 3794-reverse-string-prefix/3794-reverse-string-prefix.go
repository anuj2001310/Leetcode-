func reversePrefix(s string, k int) string {
    b := []byte(s)
    for i, j := 0, k - 1; i < j; i, j = i + 1, j - 1 {
		b[i], b[j] = b[j], b[i]
	}
	return string(b)
}