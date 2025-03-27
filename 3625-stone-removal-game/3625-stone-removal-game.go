func canAliceWin(n int) bool {
    for u := 10; u > -1; u-- {
        if n < u {
            return u & 1 != 0
        }
        n -= u
    }
    return false
}