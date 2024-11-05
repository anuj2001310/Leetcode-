func minChanges(s string) int {
	cnt := 0
	for i := 1; i < len(s); i += 2 {
		if s[i - 1] != s[i] {
			cnt++
		}
	}
	return cnt
}