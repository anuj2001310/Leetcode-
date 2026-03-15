func countCommas(n int64) int64 {
    var a int64
    var b int64
    a, b = 0, 1000
    for b <= n {
        a += (n - b + 1)
        b *= 1000
    }
    return a
}