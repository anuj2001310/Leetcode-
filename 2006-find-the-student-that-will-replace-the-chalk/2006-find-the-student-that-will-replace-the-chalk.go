func chalkReplacer(chalk []int, k int) int {
    can := 0
    for _, num := range chalk {
        can += num
    }
    k %= can
    for i := 0; i < len(chalk); i++ {
        if chalk[i] > k {
            return i
        }
        k -= chalk[i]
    }
    return -1
}