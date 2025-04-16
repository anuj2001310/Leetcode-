func f(x int) int {
    if x  < 0 {
        return -1 * (x)
    }
    return x
}
func findClosest(x int, y int, z int) int {
    d1, d2 := f(x - z), f(y - z)
    if d1 < d2 {
        return 1
    } else if d1 == d2 {
        return 0
    }
    return 2
}