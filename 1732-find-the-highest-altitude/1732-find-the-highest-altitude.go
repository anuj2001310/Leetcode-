func largestAltitude(gain []int) int {
    curr, mx := 0, 0
    for _, g := range gain {
        curr += g
        mx = max(mx, curr)
    }

    return mx
}