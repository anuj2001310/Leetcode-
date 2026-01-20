func vowelConsonantScore(s string) int {
	var v, c int
	for _, r := range s {
		switch r {
		case 'a', 'e', 'i', 'o', 'u':
			v++
		default:
			if unicode.IsLetter(r) {
				c++
			}
		}
	}
	if c > 0 {
		return v / c
	}
	return 0
}