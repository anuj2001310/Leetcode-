func clearDigits(s string) string {
    stack := []byte{}

	for i := range s {

		if s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 {
			stack = append(stack, s[i])
		} else {
			if len(stack) > 0 {
				stack = stack[:len(stack)-1]
			}

		}

	}

	return string(stack)
}