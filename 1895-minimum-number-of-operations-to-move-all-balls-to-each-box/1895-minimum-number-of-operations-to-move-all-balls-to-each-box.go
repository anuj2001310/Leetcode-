func minOperations(boxes string) []int {
    n := len(boxes)

    res := make([]int, n)
    b, m := 0, 0
    for i := 0; i < n; i++ {
        res[i] = (b + m)
        m += b
        b += int(boxes[i] - '0')
    }
    b = 0
    m = 0
    for i := n - 1; i >= 0; i-- {
        res[i] += (b + m)
        m += b
        b += int(boxes[i] - '0')
    }
    return res
}