func residuePrefixes(s string) int {
    ans, dis := 0, 0
    freq := make([]int, 26)

    for i, ch := range s {
        id := int(ch - 'a')
        if freq[id] == 0 {
            dis++
        }
        
        freq[id]++
        if (dis == (i + 1) % 3) {
            ans++
        }
    }
    return ans
}