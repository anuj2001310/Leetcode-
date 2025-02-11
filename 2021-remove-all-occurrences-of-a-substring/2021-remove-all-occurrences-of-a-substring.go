func removeOccurrences(s string, part string) string {
	for i := 0; i < len(s); i++ {
		if s[i] == part[0] {
			if i + len(part) < len(s) {
				if s[i : i + len(part)] == part {
					s = s[: i] + s[i + len(part) : ]
					i = -1
				}
			} else {
				if s[i: ] == part {
					s = s[ :i]
				}
				break
			}
		}
	}

	return s
}