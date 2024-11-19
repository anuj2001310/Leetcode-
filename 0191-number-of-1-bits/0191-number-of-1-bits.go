func hammingWeight(n int) int {
    bits := 0
    for n > 0 {
        bits++
        n &= (n - 1)
    }
    return bits
}