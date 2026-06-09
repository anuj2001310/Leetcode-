func consecutiveSetBits(n int) bool {
    cnt, p := 0, -1
    for ; n > 0; n >>= 1 {
        r := n % 2
        if r == 1 && r == p {
            cnt++
        }
        p = r
    }
    return cnt == 1
}