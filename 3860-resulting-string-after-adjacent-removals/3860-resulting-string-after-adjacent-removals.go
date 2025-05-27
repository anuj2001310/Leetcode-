func resultingString(s string) string {
    stk := make([]byte, 0, len(s))
    
	help := func(a, b byte) bool {
		v := (int(a) - int(b) + 26) % 26 
		return v == 25 || v == 1
	}
    
	for i := 0; i < len(s); i++ {
		c := s[i]
		if len(stk) != 0 && help(stk[len(stk) - 1], c) {
			stk = stk[ : len(stk) - 1]
		} else {
			stk = append(stk, c)
		}
	}
	return string(stk)
}