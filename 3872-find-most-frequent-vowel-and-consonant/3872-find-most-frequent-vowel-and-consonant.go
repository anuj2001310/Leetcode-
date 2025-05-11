func maxFreqSum(s string) int {
    n, freq := len(s), make([]int, 26)
    c, v := 0, 0
    for _, ch := range s {
        idx := int(ch - 'a')
        freq[idx]++
    }
    
    isVowel := func (ch byte) bool {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
    }

    Max := func (x, y int) int {
        if x > y {
            return x
        }
        return y
    }
    
    for i := 0; i < n; i++ {
        idx := int(s[i] - 'a')
        if isVowel(s[i]) {
            v = Max(freq[idx], v)
        } else {
            c = Max(freq[idx], c)
        }  
    }
    return c + v
}