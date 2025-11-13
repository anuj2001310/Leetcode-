func removeZeros(n int64) int64 {
    var res int64
    res = 0
    
    for n > 0 {
        r := n % 10
        if r != 0 {
            res = res * 10 + r
        }
        n /= 10
    }

    for res > 0 {
        n = n * 10 + res % 10
        res /= 10
    }
    return n
}