func finalPrices(prices []int) []int {
    n := len(prices)
    dis := make ([]int, 0)

    for i := 0; i < n - 1; i++ {
        d := prices[i]
        for j := i + 1; j < n; j++ {
            if prices[j] <= prices[i] {
                d = prices[i] - prices[j]
                break
            }
        }
        dis = append(dis, d)
    }
    dis = append(dis, prices[n - 1])
    return dis
}