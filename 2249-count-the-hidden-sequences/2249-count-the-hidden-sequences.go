func numberOfArrays(differences []int, lower int, upper int) int {
    curr, min, max := 0, 0, 0
    for _, d := range differences {
        curr += d
        if curr < min {
            min = curr
        }
        if curr > max {
            max = curr
        }

        if (upper - max) - (lower - min) + 1 <= 0 {
            return 0
        }
    }
    return (upper - lower) - (max - min) + 1
}