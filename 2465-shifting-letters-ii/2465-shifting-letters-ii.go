func shiftingLetters(s string, shifts [][]int) string {
    n := len(s)
    prefix := make([]int, n + 1)

    for _, shift := range shifts {
        st := shift[0]
        ed := shift[1]
        dr := shift[2]

        prefix[st] += (2 * dr - 1)
        prefix[ed + 1] -=  (2 * dr - 1)
    }

    cur := 0
    sb := []rune{}
    for i := 0; i < n; i++ {
        cur = (cur + prefix[i]) % 26
        ch := rune('a' + (int(s[i]) - int('a') + cur + 26) % 26)
        sb = append(sb, ch)
    }

    return string(sb)
}