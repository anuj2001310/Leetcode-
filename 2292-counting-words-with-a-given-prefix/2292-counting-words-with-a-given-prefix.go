func prefixCount(words []string, pref string) int {
    cnt := 0
    for _, word := range words {
        if strings.HasPrefix(word, pref) {
            cnt++
        }
    }

    return cnt
}