func minimumLength(s string) int {
    n := len(s)
    freq := make([]int, 26)
    for _, ch := range s {
        freq[ch - 'a']++
    }
    ans := 0
    for i := 0; i < n; i++ {
        if freq[s[i] - 'a'] > 2 {
            freq[s[i] - 'a'] -= 2
        }
    }
    for _, num := range freq {
        ans += num
    }
    return ans
}