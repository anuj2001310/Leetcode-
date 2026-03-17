func v(ch byte) bool {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
}

func trimTrailingVowels(s string) string {
    n := len(s)
    id := n - 1
    for id >= 0 {
        if !v(s[id]) {
            break
        }
        id -= 1
    }
    return s[: id + 1]
}