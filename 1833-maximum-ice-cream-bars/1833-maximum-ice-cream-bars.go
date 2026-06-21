func maxIceCream(costs []int, coins int) int {
    n, ct := len(costs), 0

    sort.Ints(costs)

    for i := 0; i < n; i++ {
        if coins - costs[i] < 0 {
            break
        }
        coins -= costs[i]
        ct++
    }
    return ct
}