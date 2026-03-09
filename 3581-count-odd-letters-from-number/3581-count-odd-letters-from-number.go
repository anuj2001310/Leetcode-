func countOddLetters(n int) int {
	arr := []string{
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine",
	}

	freq := make([]int, 26)

	for n > 0 {
		r := n % 10
		for _, ch := range arr[r] {
			freq[ch-'a']++
		}
		n /= 10
	}

	c := 0
	for i := 0; i < 26; i++ {
		if (freq[i] & 1) != 0 {
			c++
		}
	}

	return c
}