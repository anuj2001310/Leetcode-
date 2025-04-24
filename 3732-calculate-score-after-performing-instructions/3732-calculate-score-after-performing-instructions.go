func calculateScore(instructions []string, values []int) int64 {
    n := len(values)
    vis := make([]bool, n)
    var sum int64
    sum = 0
    for i := 0; i < n && i >= 0 && !vis[i]; {
        vis[i] = true
        if instructions[i] == "add" {
            sum += int64(values[i])
            i++
        } else {
            i += values[i]
        }
    }
    return sum
}