package main

func funcCheck(w1, w2 string) bool {
	n, m := len(w1), len(w2)
	if n > m {
		return false
	}
	flag := true
	for l1, r1, l2, r2 := 0, n - 1, 0, m - 1; l1 < n && r1 >= 0 && l2 < m && r2 >= 0 && flag; l1, r1, l2, r2 = l1 + 1, r1 - 1, l2 + 1, r2 - 1 {
		if w1[l1] != w2[l2] || w1[r1] != w2[r2] {
			flag = false
		}
	}
	return flag
}

func countPrefixSuffixPairs(words []string) int {
	l := len(words)
	ans := 0
	for i := 0; i < l; i++ {
		for j := i + 1; j < l; j++ {
			if funcCheck(words[i], words[j]) {
				ans++
			}
		}
	}
	return ans
}