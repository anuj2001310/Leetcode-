func smallestNumber(n int, t int) int {
    for {
        num := n
        pro := 1
        for  num > 0 {
            pro *= (num % 10)
            num /= 10
        }
        if pro % t == 0 {
            return n
        }
        n++
    }
    return -1
}