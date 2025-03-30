func reverseDegree(s string) int {
    sum := 0
    for i, ch := range s {
        sum += ((26 - int(ch - 'a')) * (i + 1))
    }
    return sum
}