func Max (l int, r int) int{
    if l >= r {
        return l
    }
    return r
}
func maxScore(s string) int {
    o := 0
    for _, ch := range s {
        if ch == '1' {
            o++
        }
    }

    n := len(s)
    ans, z := 0, 0
    for i := 0; i < n - 1; i++ {
        if s[i] == '1' {
            o--
        } else {
            z++
        }
        ans = Max(ans, z + o)
    }
    return ans
}